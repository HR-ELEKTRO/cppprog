// Overloading van memberfuncties

import std;
using namespace std;

class Class {
public:
    void f() const {
        println("Ik ben f()");
    }
    void f(int i) const { // overload f()
        println("Ik ben f(int i): i = {}", i);
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
Ik ben f(int i): i = 3
*/
