import std;
using namespace std;

// formatting for complex<T>
// default format: (<real_part>,<imaginary_part>) // compatible with ostream's default format for complex numbers (formatted as a pair of values)
// format specifier: <custom_format_specifier><string_format_specifier>:<T_format_specifier>
// custom format specifiers:
// 'm' for (<real_part>+/-<imaginary_part>i) // mathematical format
// 'i' for <real_part>+/-<imaginary_part>i // mathematical format without parentheses
// 'j' for (<real_part>+/-<imaginary_part>j) // engineering format

template<typename T> 
struct std::formatter<complex<T>> {
    constexpr auto parse(auto& context) {
        parentheses = true;
        as_pair = true;
        imag_unit.clear();
        string_format.clear();
        T_format.clear();
        auto iter {begin(context)};
        if (iter == end(context) || *iter == '}') { 
            return iter; 
        }
        int number_of_parsed_colons {0};
        switch (*iter) {
            case 'm': // 'm' for mathematical
                as_pair = false;
                imag_unit = 'i'; 
                iter++;
                break;
            case 'i': // 'i' for matihematical without parentheses
                as_pair = false;
                imag_unit = 'i';
                parentheses = false; 
                iter++;
                break;
            case 'j': // 'j' for engineering
                as_pair = false;
                imag_unit = 'j';
                parentheses = false; 
                iter++;
                break;
            case ':':
                ++number_of_parsed_colons;
                iter++;
                break;
        }
        for (; iter != end(context); ++iter) {
            if (*iter == '}') { 
                break; 
            }
            if (number_of_parsed_colons == 0) { // Parsing string format
                if (*iter == ':') {
                     ++number_of_parsed_colons;
                } else {
                    string_format += *iter;
                }
            } 
            else if (number_of_parsed_colons == 1) { // Parsing T format
                T_format += *iter;
            }
        }
        return iter;
    }
    auto format(const complex<T>& z, auto& context) const {
        T real_part {z.real()};
        T imag_part {z.imag()};
        T imag_abs {abs(imag_part)};
        bool imag_is_neg {imag_part < 0};
        string T_fmt {T_format.empty() ? "{}" : "{:" + T_format + "}" };
        string string_fmt {string_format.empty() ? "{}" : "{:" + string_format + "}"};
        string output_text {
            (parentheses ? "(" : "") + 
            vformat(T_fmt, make_format_args(real_part)) +
            (as_pair ? "," : (imag_is_neg ? "-" : "+")) + 
            vformat(T_fmt, make_format_args(as_pair ? imag_part : imag_abs)) + 
            imag_unit + 
            (parentheses ? ")" : "")
        };
        string final_output {vformat(string_fmt, make_format_args(output_text))};
        return format_to(context.out(), "{}", final_output);
    }
private:
    string string_format;
    string T_format;
    string imag_unit;
    bool parentheses;
    bool as_pair;
};

int main() {
    complex<double> z {3.14E4, 6.28E-4};
    cout << "z = " << z << '\n';    // z = (31400,0.000628)
    println("z = {}", z);           // z = (31400,0.000628)
    println("z = {:m}", z);         // z = (31400+0.000628i)
    println("z = {:i}", z);         // z = 31400+0.000628i
    println("z = {:j}", z);         // z = 31400+0.000628j
    println("z = {:j:a}", z);       // z = 1.eaap+14+1.4940bbb1f255fp-11j
    println("z = {:j:A}", z);       // z = 1.EAAP+14+1.4940BBB1F255FP-11j
    println("z = {:j:.4e}", z);     // z = 3.1400e+04+6.2800e-04j
    println("z = {:j:.4E}", z);     // z = 3.1400E+04+6.2800E-04j
    println("z = {:j:f}", z);       // z = 31400.000000+0.000628j
    println("z = {:j:g}", z);       // z = 31400+0.000628j
    println("z = {:j:G}", z);       // z = 31400+0.000628j
    println("z = {:j:.3f}", z);     // z = 31400.000+0.001j
    println("z = {:j_>25:.3f}", z); // z = _________31400.000+0.001j
    println("z = {:j_>25:.4f}", z); // z = _______31400.0000+0.0006j
    println("z = {:j_>25:.5f}", z); // z = _____31400.00000+0.00063j
    println("z = {:j_>25:.6f}", z); // z = ___31400.000000+0.000628j
    println("z = {:j_>25:f}", z);   // z = ___31400.000000+0.000628j
    // Total width before ':' and per-value width/precision after ':'
    println("z = {:>25:>10.3f}", z);    // z =   ( 31400.000,     0.001)
    println("z = {:j>25:>10.3f}", z);   // z =     31400.000+     0.001j
    println("z = {:j*>25:#>10.3f}", z); // z = ***#31400.000+#####0.001j
    println("z = {:j*^25:#^10.3f}", z); // z = *31400.000#+##0.001###j**
    println("z = {:j*<25:#<10.3f}", z); // z = 31400.000#+0.001#####j***
    println("z = {:>25:>10.2e}", z);    // z =   (  3.14e+04,  6.28e-04)
    println("z = {:m>25:>10.2e}", z);   // z =  (  3.14e+04+  6.28e-04i)
    println("z = {:i>25:>10.2e}", z);   // z =      3.14e+04+  6.28e-04i
    println("z = {:j>25:>10.2e}", z);   // z =      3.14e+04+  6.28e-04j
    println("z = {:j*>25:#>10.2e}", z); // z = ***##3.14e+04+##6.28e-04j
    println("z = {:j*^25:#^10.2e}", z); // z = *#3.14e+04#+#6.28e-04#j**
    println("z = {:j*<25:#<10.2e}", z); // z = 3.14e+04##+6.28e-04##j***
    // dit werkt niet:
    // int precision;
    // print("Geef de gewenste precisie op: ");
    // cin >> precision;
    // println("z = {::>.{}f}", z, precision);
}

/* Output:
z = (31400,0.000628)
z = (31400,0.000628)
z = (31400+0.000628i)
z = 31400+0.000628i
z = 31400+0.000628j
z = 1.eaap+14+1.4940bbb1f255fp-11j
z = 1.EAAP+14+1.4940BBB1F255FP-11j
z = 3.1400e+04+6.2800e-04j
z = 3.1400E+04+6.2800E-04j
z = 31400.000000+0.000628j
z = 31400+0.000628j
z = 31400+0.000628j
z = 31400.000+0.001j
z = _________31400.000+0.001j
z = _______31400.0000+0.0006j
z = _____31400.00000+0.00063j
z = ___31400.000000+0.000628j
z = ___31400.000000+0.000628j
z =   ( 31400.000,     0.001)
z =     31400.000+     0.001j
z = ***#31400.000+#####0.001j
z = *31400.000#+##0.001###j**
z = 31400.000#+0.001#####j***
z =   (  3.14e+04,  6.28e-04)
z =  (  3.14e+04+  6.28e-04i)
z =      3.14e+04+  6.28e-04i
z =      3.14e+04+  6.28e-04j
z = ***##3.14e+04+##6.28e-04j
z = *#3.14e+04#+#6.28e-04#j**
z = 3.14e+04##+6.28e-04##j***
*/
