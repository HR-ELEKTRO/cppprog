#include <iostream>
using namespace std;

constexpr unsigned int cpow(unsigned int n, unsigned int m) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < m; ++i) {
        result *= n;
    }
    return result;
}

constexpr unsigned int cpowr(unsigned int n, unsigned int m) {
    return m == 0 ? 1 : n * cpowr(n, m - 1);
}

int main() {
    constexpr unsigned int c1 = cpow(3, 5);
    cout << "3^5 = " << c1 << '\n';

    constexpr unsigned int c2 = cpowr(3, 5);
    cout << "3^5 = " << c2 << '\n';

    unsigned int a, b;
    cout << "Geef een integer: ";
    cin >> a;
    cout << "Geef nog een integer: ";
    cin >> b;
    
//  constexpr unsigned int c3 = cpow(a, b);
//  Error: the value of `a' is not usable in a constant expression
    
    cout << "a^b = " << cpow(a, b) << '\n';
    cout << "a^b = " << cpowr(a, b) << '\n';
}
