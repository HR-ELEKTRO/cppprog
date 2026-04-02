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

complex<double> impedance_C(double c, double f) {
    if (c == 0.0)
        throw domain_error {"Capaciteit == 0"};
    if (f == 0.0)
        throw domain_error {"Frequentie == 0"};
    return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
}

int main() {
    try {
        println("Z = {:.3f}", impedance_C(1e-6, 1e3));
        println("Z = {:.3f}", impedance_C(1e-6, 0));
        println("Dit was het!");
    } catch (const domain_error& e) {
        println("Fout: {}", e.what());
    }
    println("The END.");
}

/* Uitvoer:
Z = 0.000-159.155j
Fout: Frequentie == 0
The END.
*/
