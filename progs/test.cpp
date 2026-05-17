import std;
using namespace std;

class Hond { /* ... */ };
class Sint_bernard: public Hond { /* ... */ };

class test {
public:
    enum {tien = 10, elf};
};

int a[test::tien]; // werkt dit? Ja natuurlijk.

int main() {
    [[maybe_unused]] int a, b{}, c;
// (a+b)+=c;
//  error: lvalue required as left operand of assignment
    a = ++++b;
//  a = b++++;
//  error: lvalue required as increment operand
    [[maybe_unused]] std::list<int> l {12, 18, 6};
//  sort(l.begin(), l.end());
//  error: no match for ‘operator-’
    [[maybe_unused]] int i;
//  i = "Hallo";
//  error: invalid conversion from 'const char*' to 'int'
//  i = (int)"Hallo";
//  error: cast from 'const char*' to 'int' loses precision
//  i = int("Hallo");
//  error: cast from 'const char*' to 'int' loses precision
//  i = reinterpret_cast<int>("Hallo");
//  error: cast from 'const char*' to 'int' loses precision
    using ll = long long;
    [[maybe_unused]] ll i64;
    i64 = (ll)"Hallo";
    i64 = ll("Hallo");
    i64 = reinterpret_cast<ll>("Hallo");
    Sint_bernard boris;
	[[maybe_unused]] Hond& h {boris}; // OK: een Sint_bernard is een Hond
	[[maybe_unused]] Hond fikkie;
//  Sint_bernard& sb {fikkie}; // NOT OK: een Hond is geen Sint_bernard
// error: cannot bind non-const lvalue reference of type 'Sint_bernard&' to an rvalue of type 'Sint_bernard'
    [[maybe_unused]] Hond* hp {&boris}; // OK: een Sint_bernard is een Hond
//  [[maybe_unused]] Sint_bernard* sbp {&fikkie}; // NOT OK: een Hond is geen Sint_bernard
//  error: invalid conversion from 'Hond*' to 'Sint_bernard*' 
	vector v1 {1, 2, 3}; // v1 is van het type vector<int>
    println("v1 = {}", v1);
	vector v2 {v1}; // v2 is ook van het type vector<int>
    println("v2 = {}", v2);
    double d {12345.67890};
    bool wetenschappelijke_notatie {true};
    // println("{:{}}", wetenschappelijke_notatie ? "e" : "f", 12345.67890);
    // terminate called after throwing an instance of 'std::format_error'
    //  what():  format error: argument used for width or precision must be a non-negative integer
    // Aborted
    if (wetenschappelijke_notatie) {
        println("{:e}", d);
    } else {
        println("{:f}", d);
    }
    wetenschappelijke_notatie = false;
    println("{}", vformat(wetenschappelijke_notatie ? "{:e}" : "{:f}", make_format_args(d)));
    wetenschappelijke_notatie = true;
    vprint_unicode(wetenschappelijke_notatie ? "{:e}\n" : "{:f}\n", make_format_args(d));
}