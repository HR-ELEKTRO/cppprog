#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI = atan(1.0) * 4;

complex<double> impedance_C(double c, double f) {
    assert(c != 0.0 && f != 0.0);
    return complex<double>{0, -1 / (2 * PI * f * c)};
}

int main() {
    cout << impedance_C(1e-6, 1e3) << '\n';
    cout << impedance_C(1e-6, 0) << '\n';
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
assertion "c != 0.0 && f != 0.0" failed: file "ImpedanceC2.cpp", line 11, function: std::complex<double> impedance_C(double, double)
*/
