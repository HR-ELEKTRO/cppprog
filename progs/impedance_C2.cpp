import std;
#include <cassert>
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
    assert(c != 0.0 && f != 0.0);
    return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
}

int main() {
    println("{:.3f}", impedance_C(1e-6, 1e3));
    println("{:.3f}", impedance_C(1e-6, 0));
    println("The END.");
}

/* Uitvoer:
0.000-159.155j
assertion "c != 0.0 && f != 0.0" failed: file "impedance_C2.cpp", line 18, function: std::complex<double> impedance_C(double, double)
Aborted
*/
