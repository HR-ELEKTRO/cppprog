#include <iostream>
#include <complex>
#include <cmath>
#include <stdexcept>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

complex<double> impedanceC(double c, double f) {
    if (c == 0.0)
        throw domain_error("Capaciteit == 0");
    if (f == 0.0)
        throw domain_error("Frequentie == 0");
    return complex<double>(0, -1 / (2 * PI * f * c));
}

int main() {
    try {
        cout << impedanceC(1e-6, 1e3) << endl;
        cout << impedanceC(1e-6, 0) << endl;
        cout << "Dit was het!" << endl;
    } catch (domain_error& e) {
        cout << e.what() << endl;
    }
    cout << "The END." << endl;
    cin.get();
    return 0;
}

/*
Uitvoer:

(0,-159.155)
Frequentie == 0
The END.
*/
