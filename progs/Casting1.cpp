#include <iostream>
using namespace std;

// Dit programma zet een c-string om naar een int.
// Dit slaat inderdaad nergens op maar laat wel zien hoe we compiler kunnen dwingen om zoiets toch te doen
// door middel van een zogenaamde type cast

int main() {
    int i;
//  i = "Hallo";
//  [C++ Error (Microsoft)] '=' : cannot convert from 'const char [6]' to 'int'
//  [C++ Error (GCC)]       invalid conversion from 'const char*' to 'int'
    i = (int)"Hello"; // oude C syntax
    cout << i << endl;
    i = int("Bello"); // oude C++ syntax
    cout << i << endl;
    i = reinterpret_cast<int>("Bella"); // nieuwe C++ syntax
    cout << i << endl;
    cin.get();
    return 0;
}

/*
Output:

4282528
4282520
4282416
*/
