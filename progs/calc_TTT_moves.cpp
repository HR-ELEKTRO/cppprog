#include <iostream>
using namespace std;

long long fac(long long n) {
    long long res {1};
    for (long long i {2}; i <= n; ++i)
        res *= i;
    return res;
}

int main() {
    cout << "Geef aantal hokjes: ";
    long long n;
    cin >> n;
    if (n > 20) {
        cout << "Sorry het aantal stellingen past niet in een long long\n";
    }
    else {
        cout << "Aantal stellingen:\n";
        long long res {0};
        for (long long i {0}; i <= n; ++i) {
            long long t {fac(n) / fac(n - i)};
            cout << t << " + " << '\n';
            res += t;
        }
        cout<< "= " << res << '\n';
    }
}
