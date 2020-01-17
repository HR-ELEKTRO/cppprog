// Template functie swap

#include <iostream>
using namespace std;

template <typename T> void swap(T& p, T& q) {
    T t {p};
    p = q;
    q = t;
}

int main() {
    int n {2};
    int m {3};
    cout << "n = " << n << " m = " << m << '\n';
    ::swap(n, m);
    cout << "n = " << n << " m = " << m << '\n';
    double x {2.2};
    double y {3.3};
    cout << "x = " << x << " y = " << y << '\n';
    ::swap(x, y);
    cout << "x = " << x << " y = " << y << '\n';
}
