// Overloading van memberfuncties en de hiding rule

import std;
using namespace std;

/*
    Dit voorbeeld laat zien dat de hiding rule een programma
    beter onderhoudbaar maakt!
*/

// Code van Bas
class Base {
public:
// Als Bas deze code later toevoegt heeft Dewi hier GEEN last van!
// void f(int i) const {
//     println("Ik ben Base::f(int i): i = {}", i);
// }
};

// Code van Dewi
class Derived: public Base {
public:
    void f(double d) const {
        println("Ik ben Derived::f(double d): d = {:.2f}", d);
    }
};

int main() {
    Derived d;
        d.f(3);
}

/* 
Output zonder Base::f(int):
Ik ben Derived::f(double d): d = 3.00

Output met Base::f(int):
Ik ben Derived::f(double d): d = 3.00
*/
