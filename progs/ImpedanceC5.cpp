#include <complex>
#include <cmath>
#include <iostream>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI = atan(1.0) * 4;

class FrequencyError {};
class CapacityError {};

complex<double> impedanceC(double c, double f) {
    if (c == 0.0)
        throw CapacityError();
    if (f == 0.0)
        throw FrequencyError();
    return complex<double>{0, -1 / (2 * PI * f * c)};
}

int main() {
    try {
        cout << impedanceC(1e-6, 1e3) << '\n';
        cout << impedanceC(1e-6, 0) << '\n';
        cout << "Dit was het!\n";
    } catch (const CapacityError&) {
        cout << "Capaciteit == 0\n";
    } catch (const FrequencyError&) {
        cout << "Frequentie == 0\n";
    }
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
Frequentie == 0
The END.
*/