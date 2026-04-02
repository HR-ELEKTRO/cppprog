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

complex<double> impedance_C(double c, double f) {
    return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
}

int main() {
    println("{:.3f}", impedance_C(1e-6, 1e3));
    println("{:.3f}", impedance_C(1e-6, 0));
    println("The END.");
}

/* Uitvoer:
0.000-159.155j
0.000-infj
The END.
*/
