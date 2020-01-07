#include <iostream>
using namespace std;

int ggd(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != 0) {
        auto t = m;
        m = n % m;
        n = t;
    }
    return n;
}

int main() {
    if (ggd(-110, -20) != 10) cout << "Test 1 faalt!\n";
    else cout << "Test 1 geslaagd!" << endl;
    if (ggd(110, 20) != 10) cout << "Test 2 faalt!\n";
    else cout << "Test 2 geslaagd!" << endl;
    if (ggd(661, 1583) != 1) cout << "Test 3 faalt!\n";
    else cout << "Test 3 geslaagd!" << endl;
    if (ggd(661*7, 1583*14) != 7) cout << "Test 4 faalt!\n";
    else cout << "Test 4 geslaagd!" << endl;
    if (ggd(0, 1583) != 1583) cout << "Test 5 faalt!\n";
    else cout << "Test 5 geslaagd!" << endl;
    if (ggd(661, 0) != 661) cout << "Test 6 faalt!\n";
    else cout << "Test 6 geslaagd!\n";
    cout << "finished!\n";
}