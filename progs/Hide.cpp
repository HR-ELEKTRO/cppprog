// Overloading van memberfuncties en de hiding rule

// Dit voorbeeld laat zien hoe het NIET moet!
// Je moet overloading en overerving NIET combineren!

#include <iostream>
using namespace std;

class Base {
public:
    void f() const {
        cout << "Ik ben f()" << endl;
    }
};

class Derived: public Base {
public:
    void f(int i) const { // Verberg f() !! Geen goed idee !!!
        cout << "Ik ben f(int)" << endl;
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
//  [C++ Error (Microsoft)]: 'Derived::f' : function does not take 0 arguments
//  [C++ Error (GCC)]:       no matching function for call to 'Derived::f()'
    d.Base::f();

    func(b);
    func(d); // Dit geeft geen error !!!

    cin.get();
    return 0;
}

/*
Output:
Ik ben f()
Ik ben f(int)
Ik ben f()
Ik ben f()
Ik ben f()
*/
