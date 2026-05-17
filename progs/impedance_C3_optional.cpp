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

optional<complex<double>> impedance_C(double c, double f) {
    if (c != 0.0 && f != 0.0) {
        return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
    }
    else
        return {};
}

int main() {
    auto result = impedance_C(1e-6, 1e3);
    if (result) {
        println("{:.3f}", *result);
    }
    else {
        println("Kan impedantie niet berekenen.");
    }
    result = impedance_C(1e-6, 0);
    if (result.has_value()) {
        println("{:.3f}", result.value());
    }
    else {
        println("Kan impedantie niet berekenen.");
    }
}

/* Uitvoer:
0.000-159.155j
Kan impedantie niet berekenen.
The END.
*/
