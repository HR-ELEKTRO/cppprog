import std;
using namespace std;

template<typename T> 
struct std::formatter<complex<T>>: public formatter<T> {
    auto format(const complex<T>& z, auto& context) const {
        context.advance_to(formatter<T>::format(z.real(), context));
        if (z.imag() >= 0) {
            context.advance_to(format_to(context.out(), "+"));
        } else {
            context.advance_to(format_to(context.out(), "-"));
        }
        context.advance_to(formatter<T>::format(abs(z.imag()), context));
        return format_to(context.out(), "j");
    }
};

int main() {
    complex<double> z1 {1.2345, -2.9876};
    complex<double> z2 {3.14E4, 6.28E-4};
    cout << "z1 = " << z1 << '\n'; // z1 = (1.2345,-2.9876)
    cout << "z2 = " << z2 << '\n'; // z2 = (31400,0.000628)
    println("z1 = {}", z1);        // z1 = 1.2345-2.9876j
    println("z2 = {}", z2);        // z2 = 31400+0.000628j
    println("z1 = {:.3f}", z1);    // z1 = 1.234-2.988j
    println("z2 = {:.3f}", z2);    // z2 = 31400.000+0.001j
    println("z1 = {:.3e}", z1);    // z1 = 1.234e+00-2.988e+00j
    println("z2 = {:.3e}", z2);    // z2 = 3.140e+04+6.280e-04j
    println("z1 = {:.3g}", z1);    // z1 = 1.23-2.99j
    println("z2 = {:.3g}", z2);    // z2 = 3.14e+04+0.000628j
    // dit werkt misschien anders dan verwacht:
    println("z1 = {:>10.3f}", z1); // z1 =      1.234-     2.988j
    println("z2 = {:>10.3e}", z2); // z2 =  3.140e+04+ 6.280e-04j
    int precision;
    print("Geef de gewenste precisie op: ");
    cin >> precision;
    println("z1 = {:>.{}f}", z1, precision);
    println("z2 = {:>.{}f}", z2, precision);
}

/* Output 
z1 = (1.2345,-2.9876)
z2 = (31400,0.000628)
z1 = 1.2345-2.9876j
z2 = 31400+0.000628j
z1 = 1.234-2.988j
z2 = 31400.000+0.001j
z1 = 1.234e+00-2.988e+00j
z2 = 3.140e+04+6.280e-04j
z1 = 1.23-2.99j
z2 = 3.14e+04+0.000628j
z1 =      1.234-     2.988j
z2 =  3.140e+04+ 6.280e-04j
*/