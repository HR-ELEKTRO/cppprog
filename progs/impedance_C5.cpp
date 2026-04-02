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

class Frequency_error {};
class Capacity_error {};

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
    } catch (const Capacity_error&) {
        println("Capaciteit == 0");
    } catch (const Frequency_error&) {
        println("Frequentie == 0");
    }
    println("The END.");
}

/* Uitvoer:
Z = 0.000-159.155j
Frequentie == 0
The END.
*/