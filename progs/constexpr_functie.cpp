#include <iostream>
#include <array>
using namespace std;

unsigned int power(unsigned int n, unsigned int m) {
    unsigned int result = 1;
    for (unsigned int i {0}; i < m; ++i) {
        result *= n;
    }
    return result;
}

int main() {
    cout << "3 tot de macht 5 = " << power(3, 5) << '\n';

    array<int, power(3, 5)>;
    constexpr unsigned int c1 = power(3, 5);
    cout << "3 tot de macht 5 = " << c1 << '\n';

    unsigned int a, b;
    cout << "Geef een integer: ";
    cin >> a;
    cout << "Geef nog een integer: ";
    cin >> b;
    
    cout << a << " tot de macht " << b << " = " << power(a, b) << '\n';
}
