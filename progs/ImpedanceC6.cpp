#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

class ImpedanceError {
public:
    virtual ~ImpedanceError() = default;
    virtual string getErrorMessage() const = 0;
};

class FrequencyError: public ImpedanceError {
public:
    virtual string getErrorMessage() const;
};

string FrequencyError::getErrorMessage() const {
    return "Frequentie == 0";
}

class CapacityError: public ImpedanceError {
public:
    virtual string getErrorMessage() const;
};

string CapacityError::getErrorMessage() const {
    return "Capaciteit == 0";
}

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
    } catch (const ImpedanceError& e) {
        cout << e.getErrorMessage() << '\n';
    }
    cout << "The END.\n";
}

/* Uitvoer:
(0,-159.155)
Frequentie == 0
The END.
*/
