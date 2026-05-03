// Template functie swap

import std;
using namespace std;

void swap(auto& p, auto& q) {
    auto t {p};
    p = q;
    q = t;
}

int main() {
    int n {2};
    int m {3};
    println("n = {} m = {}", n, m);
    ::swap(n, m);
    println("n = {} m = {}", n, m);

    double x {2.2};
    double y {3.3};
    println("x = {} y = {}", x, y);
    ::swap(x, y);
    println("x = {} y = {}", x, y);

    ::swap(n, x);
    println("n = {} x = {}", n, x);
}
