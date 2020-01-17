#include <iostream>
using namespace std;

class Base {
public:
    void f(int i) const {
        cout << "Base::f(int) called.\n";
    }
    virtual void g(int i) const {
        cout << "Base::g(int) called.\n";
    }
};

class Derived: public Base {
public:
    void f(int i) const override {
        cout << "Derived::f(int) called.\n";
    }
    void g(int i) override {
        cout << "Derived::g(int) called.\n";
    }
};

/* 
In de bovenstaande afgeleide class is het de bedoeling om zowel f als g te overridden.
Beide functies worden echter NIET overridden.
f wordt niet overridden omdat f in de base class niet virtual is gedeclareerd.
g wordt niet overridden omdat g in de base class const is en in de derived class niet.
Door expliciet aan te geven dat we f en g willen overridden geeft de compiler een foutmelding.

De GCC C++ compiler geeft de volgende foutmeldingen:
'void Derived::f(int) const' marked override, but does not override
'void Derived::g(int)' marked override, but does not override
*/

int main() {
    Derived d;
    Base* pb {&d};
    pb->f(3);
    pb->g(3);
}
