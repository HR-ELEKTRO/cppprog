#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

complex<double> impedanceC(double c, double f) {
    assert(c != 0.0 && f != 0.0);
    return complex<double>(0, -1 / (2 * PI * f * c));
}

int main() {
    cout << impedanceC(1e-6, 1e3) << endl;
    cout << impedanceC(1e-6, 0) << endl;
    cout << "The END." << endl;
    cin.get();
    return 0;
}

/*
(0,-159.155)
Assertion failed: c != 0.0 && f != 0.0, file impedancec2.cpp, line 11
*/
