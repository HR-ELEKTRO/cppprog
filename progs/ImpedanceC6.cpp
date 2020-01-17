#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

class Impedance_error {
public:
    virtual ~Impedance_error() = default;
    virtual string get_error_message() const = 0;
};

class Frequency_error: public Impedance_error {
public:
    string get_error_message() const override;
};

string Frequency_error::get_error_message() const {
    return "Frequentie == 0";
}

class Capacity_error: public Impedance_error {
public:
    string get_error_message() const override;
};

string Capacity_error::get_error_message() const {
    return "Capaciteit == 0";
}

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
    } catch (const Impedance_error& e) {
        cout << e.get_error_message() << '\n';
    }
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
Frequentie == 0
The END.
*/
