import std;
using namespace std;

// verschil tussen lvalue reference en rvalue reference

void f(int& ilr) {
    println("f(int& ilr) is aangeroepen met ilr = {}", ilr);
}

void f(int&& irr) {
    println("f(int&& irr) is aangeroepen met irr = {}", irr);
}

int main() {
    int a {1};
    int b {2};

    int& r1 {a}; // r1 is een andere naam voor a
    println("r1 = {}", r1);
//  int& r2 {a + b};
//  error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    const int& r3 {a + b};
    println("r3 = {}", r3);
//  r3 = 5;
//  error: assignment of read-only reference 'r3'
//  int&& r4 {a};
//  error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
    int&& r5 {a + b}; // r4 is een andere naam voor het resultaat van a + b
    println("r5 = {}", r5);
    r5 = 5;
    println("r5 = {}", r5);
    
    f(0);
    f(a);
    f(a + b);
}