#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI {atan(1.0) * 4};

bool impedance_C(complex<double>& res, double c, double f) {
    if (c != 0.0 && f != 0.0) {
        res = complex<double> {0, -1 / (2 * PI * f * c)};
        return true;
    }
    else
        return false;
}

int main() {
    complex<double> z;
    if (impedance_C(z, 1e-6, 1e3)) 
        cout << z << '\n';
    else
        cout << "Kan impedantie niet berekenen.\n";
    if (impedance_C(z, 1e-6, 0)) 
        cout << z << '\n';
    else 
        cout << "Kan impedantie niet berekenen.\n";
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
Kan impedantie niet berekenen.
The END.
*/
