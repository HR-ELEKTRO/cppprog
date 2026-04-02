import std;
using namespace std;

template<typename T> 
struct std::formatter<complex<T>>: public formatter<T> {
    auto format(const complex<T>& z, auto& context) const {
        context.advance_to(formatter<T>::format(z.real(), context));
        if (z.imag() >= 0)
            context.advance_to(format_to(context.out(), "+"));
        context.advance_to(formatter<T>::format(z.imag(), context));
        context.advance_to(format_to(context.out(), "j"));
        return context.out();
    }
};

bool impedance_C(complex<double>& res, double c, double f) {
    if (c != 0.0 && f != 0.0) {
        res = complex<double> {0, -1 / (2 * numbers::pi * f * c)};
        return true;
    }
    else
        return false;
}

int main() {
    complex<double> z;
    if (impedance_C(z, 1e-6, 1e3)) 
        println("{:.3f}", z);
    else
        println("Kan impedantie niet berekenen.");
    if (impedance_C(z, 1e-6, 0)) 
        println("{:.3f}", z);
    else 
        println("Kan impedantie niet berekenen.");
    println("The END.");
}

/* Uitvoer:
0.000-159.155j
Kan impedantie niet berekenen.
The END.
*/
