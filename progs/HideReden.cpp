// Overloading van memberfuncties en de hiding rule

#include <iostream>
using namespace std;

/*
    Dit voorbeeld laat zien dat de hiding rule een programma
    beter onderhoudbaar maakt!
*/

// Code van Bas
class Base {
public:
// Als Bas deze code later toevoegt heeft Dewi hier GEEN last van!
//  void f(int i) const {
//      cout << "Ik ben f(int)" << endl;
//  }
};

// Code van Dewi
class Derived: public Base {
public:
    void f(double d) const {
        cout << "Ik ben f(double)" << endl;
    }
};

int main() {
    Derived d;
    d.f(3);
    cin.get();
    return 0;
}

/*
Output zonder Base::f(int):
Ik ben f(double)

Output met Base::f(int):
Ik ben f(double)
*/
