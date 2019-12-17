// Overloading van memberfuncties

#include <iostream>
using namespace std;

class Class {
public:
    void f() const {
        cout << "Ik ben f()" << endl;
    }
    void f(int i) const { // overload f()
        cout << "Ik ben f(int)" << endl;
    }
};

int main() {
    Class object;
    object.f();  // de compiler kiest zelf de juiste functie
    object.f(3); // de compiler kiest zelf de juiste functie
//  ...
    cin.get();
    return 0;
}

/*
Output:
Ik ben f()
Ik ben f(int)
*/
