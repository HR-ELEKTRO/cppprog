import std;
using namespace std;

template<typename T> 
struct std::formatter<std::complex<T>>: public formatter<T> {
    auto format(const std::complex<T>& z, auto& context) const {
        context.advance_to(formatter<T>::format(z.real(), context));
        if (z.imag() >= 0)
            context.advance_to(format_to(context.out(), "+"));
        context.advance_to(formatter<T>::format(z.imag(), context));
        context.advance_to(format_to(context.out(), "j"));
        return context.out();
    }
};

class Impedance_error {
public:
    virtual ~Impedance_error() = default;
    virtual string get_error_message() const = 0;
};

class Frequency_error: public Impedance_error {
public:
    string get_error_message() const override;
};

string Frequency_error::get_error_message() const {
    return "Frequentie == 0";
}

class Capacity_error: public Impedance_error {
public:
    string get_error_message() const override;
};

string Capacity_error::get_error_message() const {
    return "Capaciteit == 0";
}

complex<double> impedance_C(double c, double f) {
    if (c == 0.0)
        throw Capacity_error {};
    if (f == 0.0)
        throw Frequency_error {};
    return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
}

int main() {
    try {
        println("Z = {:.3f}", impedance_C(1e-6, 1e3));
        println("Z = {:.3f}", impedance_C(1e-6, 0));
        println("Dit was het!");
    } catch (const Impedance_error& e) {
        println("Error: {}", e.get_error_message());
    }
    println("The END.");
}

/* Uitvoer:
Z = 0.000-159.155j
Error: Frequentie == 0
The END.
*/
