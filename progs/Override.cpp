// Verschil tussen overloading en overriding!

#include <iostream>
using namespace std;

class Base {
public:
    void f(int i) const {
        cout << "Base::f(int) called." << endl;
    }
    virtual void g(int i) const {
        cout << "Base::g(int) called." << endl;
    }
// ...
};

class Derived: public Base {
public:
    void f(int i) const { // f is overloaded!
        cout << "Derived::f(int) called." << endl;
    }
    virtual void g(int i) const { // g is overridden
        cout << "Derived::g(int) called." << endl;
    }
// ...
};

int main() {
    Base b;
    Derived d;
    Base* pb = &d;
    b.f(3);
    d.f(3);
    pb->f(3);
//  pb->Derived::f(3);
//  Error (Microsoft): 'Derived' : is not a member of 'Base'
//  Error (GCC):       `Derived' is not a base of 'Base'
    b.g(3);
    d.g(3);
    pb->g(3);
    pb->Base::g(3);

    cin.get();
    return 0;
}

/*
Output:
Base::f(int) called.
Derived::f(int) called.
Base::f(int) called.
Base::g(int) called.
Derived::g(int) called.
Derived::g(int) called.
Base::g(int) called.
*/
