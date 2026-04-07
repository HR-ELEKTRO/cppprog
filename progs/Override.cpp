// Verschil tussen overloading en overriding!

import std;
using namespace std;

class Base {
public:
    void f(int i) const {
        println("Base::f(int) called: i = {}", i);
    }
    virtual void g(int i) const {
        println("Base::g(int) called: i = {}", i);
    }
// ...
};

class Derived: public Base {
public:
    void f(int i) const { // f is overloaded!
        println("Derived::f(int) called: i = {}", i);
    }
    void g(int i) const override { // g is overridden
        println("Derived::g(int) called: i = {}", i);
    }
// ...
};

int main() {
    Base b;
    Derived d;
    Base& rb{d};
    Base* pb{&d};
    b.f(1);
    d.f(2);
    rb.f(3);
    pb->f(4);
//  rb.Derived::f(666);
//  Error: 'Derived' is not a base of 'Base'
//  pb->Derived::f(666);
//  Error: 'Derived' is not a base of 'Base'
    b.g(5);
    d.g(6);
    rb.g(7);
    rb.Base::g(8);
    pb->g(9);
    pb->Base::g(10);
}

/* Output:
Base::f(int) called: i = 3
Derived::f(int) called: i = 3
Base::f(int) called: i = 3
Base::g(int) called: i = 3
Derived::g(int) called: i = 3
Derived::g(int) called: i = 3
Base::g(int) called: i = 3
*/
