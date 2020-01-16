// Reference als return type

#include <iostream>
using namespace std;

int& max(int& a, int& b) {
    if (a > b) return a;
    else return b;
}

// DE ONDERSTAANDE CODE IS NIET CORRECT !!! DANGLING REFERENCE
// GNU GCC C++ compiler geeft alleen een warning
int& som1(int i1, int i2) { // Een gemene fout
    int s {i1 + i2};
    return s;
//  Warning: reference to local variable `s' returned
}

// DE ONDERSTAANDE CODE IS NIET CORRECT !!! DANGLING POINTER
// GNU GCC C++ compiler geeft alleen een warning
int* som2(int i1, int i2) { // Een gemene fout
    int s {i1 + i2};
    return &s;
//  Warning: address of local variable `s' returned
}

// Dit is de juiste manier om de waarde van een lokale variabele terug te geven
int som3(int i1, int i2) {
    int s {i1 + i2};
    return s;
}

int main() {
    int x {3}, y {4};
    cout << "x = " << x << " y = " << y << '\n';
    max(x, y) = 2; // y is nu 2
    cout << "x = " << x << " y = " << y << '\n';
    max(x, y)++;   // x is nu 4
    cout << "x = " << x << " y = " << y << '\n';

    // DE ONDERSTAANDE CODE IS NIET CORRECT !!! DANGLING REFERENCE
    int& s1 {som1(1, 2)};
    int& s2 {som1(3, 4)};
    cout << "1 + 2 = " << s1 << '\n';
    cout << "3 + 4 = " << s2 << '\n';

    // DE ONDERSTAANDE CODE IS NIET CORRECT !!! DANGLING POINTER
    int* p1 {som2(1, 2)};
    int* p2 {som2(3, 4)};
    cout << "1 + 2 = " << *p1 << '\n';
    cout << "3 + 4 = " << *p2 << '\n';

    // Dit is wel correct
    int s3 {som3(1, 2)};
    int s4 {som3(3, 4)};
    cout << "1 + 2 = " << s3 << '\n';
    cout << "3 + 4 = " << s4 << '\n';
}

/* Uitvoer:
x = 3 y = 4
x = 3 y = 2
x = 4 y = 2
Segmentation fault (core dumped)
*/
