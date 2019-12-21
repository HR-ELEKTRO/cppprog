#include <iostream>
#include <complex>
#include <numbers>

using namespace std;

complex<double> impedanceC(double c, double f) {
    return complex<double>{0, -1 / (2 * numbers::pi * f * c)};
}

int main() {
    cout << impedanceC(1e-6, 1e3) << '\n';
    cout << impedanceC(1e-6, 0) << '\n';
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
(0,-1.#INF)
The END.
*/
