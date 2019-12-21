// Overloading van memberfuncties

#include <iostream>
using namespace std;

class Class {
public:
    void f() const {
        cout << "Ik ben f()\n";
    }
    void f(int i) const { // overload f()
        cout << "Ik ben f(int)\n";
    }
};

int main() {
    Class object;
    object.f();  // de compiler kiest zelf de juiste functie
    object.f(3); // de compiler kiest zelf de juiste functie
}

/*
Output:
Ik ben f()
Ik ben f(int)
*/
