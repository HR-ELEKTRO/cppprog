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
};

class Derived: public Base {
public:
    void f(int i) const override {
        println("Derived::f(int) called: i = {}", i);
    }
    void g(int i) override {
        println("Derived::g(int) called: i = {}", i);
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
    pb->f(1);
    pb->g(2);
}
