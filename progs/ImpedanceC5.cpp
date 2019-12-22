#include <complex>
#include <cmath>
#include <iostream>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI = atan(1.0) * 4;

class Frequency_error {};
class Capacity_error {};

complex<double> impedance_C(double c, double f) {
    if (c == 0.0)
        throw Capacity_error();
    if (f == 0.0)
        throw Frequency_error();
    return complex<double>{0, -1 / (2 * PI * f * c)};
}

int main() {
    try {
        cout << impedance_C(1e-6, 1e3) << '\n';
        cout << impedance_C(1e-6, 0) << '\n';
        cout << "Dit was het!\n";
    } catch (const Capacity_error&) {
        cout << "Capaciteit == 0\n";
    } catch (const Frequency_error&) {
        cout << "Frequentie == 0\n";
    }
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
Frequentie == 0
The END.
*/