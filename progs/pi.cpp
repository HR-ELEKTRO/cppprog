#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <typename T> constexpr T pi = atan(static_cast<T>(1)) * 4;

int main() {
    auto f{pi<float>}; // f is float
    auto d{pi<double>}; // d is double
    auto l{pi<long double>}; // d is long double
    cout << "f = " << fixed << setprecision(50) << f << '\n';
    cout << "d = " << fixed << setprecision(50) << d << '\n';
    cout << "l = " << fixed << setprecision(50) << l << '\n';
    cout << "π = 3.14159265358979323846264338327950288419716939937510\n";
}