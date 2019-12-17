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
};

class Derived: public Base {
public:
    void f(int i) const {
        cout << "Derived::f(int) called." << endl;
    }
    virtual void g(int i) {
        cout << "Derived::g(int) called." << endl;
    }
};

/* 
In de bovenstaande afgeleide class is het de bedoeling om zowel f als g te overridden.
Beide functies worden echter NIET overridden maar overloaded.
f wordt niet overridden omdat f in de base class niet virtual is gedeclareerd.
g wordt niet overridden omdat g in de base class const is en in de derived class niet.

De programmeur, die denkt zowel f als g overridden te hebben, verwachtte de volgende uitvoer:

Derived::f(int) called.
Derived::g(int) called.

De werkelijke uitvoer is echter:

Base::f(int) called.
Base::g(int) called.

Zie ExplicitOverride.cpp hoe je kunt voorkomen dat functies "per ongeluk" overloaded worden. 
*/

int main() {
    Derived d;
    Base* pb = &d;
    pb->f(3);
    pb->g(3);
    // ...
    cin.get();
    return 0;
}
