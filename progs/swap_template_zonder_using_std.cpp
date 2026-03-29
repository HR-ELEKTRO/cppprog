// Template functie swap

import std;
using std::println;

template <typename T> void swap(T& p, T& q) {
    T t {p};
    p = q;
    q = t;
}

int main() {
    int n {2};
    int m {3};
    println("n = {} m = {}", n, m);
    swap(n, m);
    println("n = {} m = {}", n, m);

    double x {2.2};
    double y {3.3};
    println("x = {} y = {}", x, y);
    swap(x, y);
    println("x = {} y = {}", x, y);

    // swap(n, "hallo"); // error: no matching function for call to 'swap(int&, const char [6])'

    // swap(n, x); // error: no matching function for call to 'swap(int&, double&)'
    // println("n = {} x = {}", n, x);
}
