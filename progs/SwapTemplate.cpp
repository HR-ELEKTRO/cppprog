// Template functie swap

#include <iostream>

template <typename T> void swap(T& p, T& q) {
    T t{p};
    p = q;
    q = t;
}

int main() {
    int n{2};
    int m{3};
    std::cout << "n = " << n << " m = " << m << '\n';
    swap(n, m);
    std::cout << "n = " << n << " m = " << m << '\n';
    double x{2.2};
    double y{3.3};
    std::cout << "x = " << x << " y = " << y << '\n';
    swap(x, y);
    std::cout << "x = " << x << " y = " << y << '\n';
}
