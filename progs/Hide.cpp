// Overloading van memberfuncties en de hiding rule

// Dit voorbeeld laat zien hoe het NIET moet!
// Je moet overloading en overerving NIET combineren!

import std;
using namespace std;

class Base {
public:
    void f() const {
        println("Ik ben Base::f()");
    }
};

class Derived: public Base {
public:
    void f(int i) const { // Verberg f() !! Geen goed idee !!!
        println("Ik ben Derived::f(int i): i = {}", i);
    }
};

void func(Base& b) {
    b.f();
}

int main() {
    Base b;
    Derived d;

    b.f();
    d.f(3);

//  d.f();
//  Error: no matching function for call to 'Derived::f()'
    d.Base::f();

    func(b);
    func(d); // Dit geeft geen error !!!
}

/*
Output:
Ik ben Base::f()
Ik ben Derived::f(int i): i = 3
Ik ben Base::f()
Ik ben Base::f()
Ik ben Base::f()
*/
