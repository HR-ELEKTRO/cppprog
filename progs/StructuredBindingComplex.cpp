#include <iostream>
#include <complex>
using namespace std;

int main() {
    complex<double> z{1, 2};
    auto [re,im]{z};
    cout << "z = " << re << " + " im << "j\n";
    // Dit kan ook werken maar is beyond the scope of the book
}
