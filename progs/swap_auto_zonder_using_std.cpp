// Template functie swap

import std;
using std::println;

void swap(auto& p, auto& q) {
    auto t {p};
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

    // int a1[] {1, 2, 3};
    // int a2[] {4, 5, 6};
    // println("a1 = {} a2 = {}", a1, a2);
    // // error in template instantiation
    // swap(a1, a2);
    // println("a1 = {} a2 = {}", a1, a2);

    // string s {"hallo"};
    // error in template instantiation
    // swap(n, s);
}
