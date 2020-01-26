#include <iostream>
using namespace std;

// verschil tussen lvalue reference en rvalue reference

void f(int& ilr) {
    cout << "f(int& ilr) is aangeroepen met ilr = " << ilr << '\n';
}

void f(int&& irr) {
    cout << "f(int&& irr) is aangeroepen met irr = " << irr << '\n';
}

int main() {
    int a {1};
    int b {2};

    int& r1 {a}; // r1 is een andere naam voor a
    cout << "r1 = " << r1 << '\n';
//  int& r2 {a + b};
//  error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    const int& r3 {a + b};
    cout << "r3 = " << r3 << '\n';
//  r3 = 5;
//  error: assignment of read-only reference 'r3'
//  int&& r4 {a};
//  error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
    int&& r5 {a + b}; // r4 is een andere naam voor het resultaat van a + b
    cout << "r5 = " << r5 << '\n';
    r5 = 5;
    cout << "r5 = " << r5 << '\n';
    
    f(0);
    f(a);
    f(a + b);
}