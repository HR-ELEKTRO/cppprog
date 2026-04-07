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
    void f(int i) const {
        println("Derived::f(int) called: i = {}", i);
    }
    void g(int i) {
        println("Derived::g(int) called: i = {}", i);
    }
};

/* 
In de bovenstaande afgeleide class is het de bedoeling om zowel f als g te overridden.
Beide functies worden echter NIET overridden maar overloaded.
f wordt niet overridden omdat f in de base class niet virtual is gedeclareerd.
g wordt niet overridden omdat g in de base class const is en in de derived class niet.

De programmeur, die denkt zowel f als g overridden te hebben, verwachtte de volgende uitvoer:

Derived::f(int) called: i = 1
Derived::g(int) called: i = 2

De werkelijke uitvoer is echter:

Base::f(int) called: i = 1
Base::g(int) called: i = 2

Zie explicit_override.cpp hoe je kunt voorkomen dat functies "per ongeluk" overloaded worden. 
*/

int main() {
    Derived d;
    Base* pb {&d};
    pb->f(1);
    pb->g(2);
    // ...
}
