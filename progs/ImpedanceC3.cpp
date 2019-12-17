#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

bool impedanceC(complex<double>& res, double c, double f) {
    if (c != 0.0 && f != 0.0) {
        res = complex<double>(0, -1 / (2 * PI * f * c));
        return true;
    }
    else
        return false;
}

int main() {
    complex<double> z;
    if (impedanceC(z, 1e-6, 1e3)) 
        cout << z << endl;
    else
        cout << "Kan impedantie niet berekenen." << endl;
    if (impedanceC(z, 1e-6, 0)) 
        cout << z << endl;
    else 
        cout << "Kan impedantie niet berekenen." << endl;
    cout << "The END." << endl;
    cin.get();
    return 0;
}

/*
Uitvoer:

(0,-159.155)
Kan impedantie niet berekenen.
The End.
*/
