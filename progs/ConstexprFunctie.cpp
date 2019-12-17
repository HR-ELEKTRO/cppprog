#include <iostream>
using namespace std;

unsigned int pow(unsigned int n, unsigned int m) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < m; ++i) {
        result *= n;
    }
    return result;
}

unsigned int powr(unsigned int n, unsigned int m) {
    return m == 0 ? 1 : n * powr(n, m - 1);
}

/*
constexpr unsigned int cpow(unsigned int n, unsigned int m) {
//  GCC C++11 error: body of constexpr function 'constexpr unsigned int powc(unsigned int, unsigned int)' not a return-statement
//  Zou moeten werken in C++14 (nog niet getest omdat GCC 5 nog niet beschikbaar is).
    unsigned int result = 1;
    for (unsigned int i = 0; i < m; ++i) {
        result *= n;
    }
    return result;
}
*/

constexpr unsigned int cpowr(unsigned int n, unsigned int m) {
    return m == 0 ? 1 : n * cpowr(n, m - 1);
}

int main() {
    cout << "3^5 = " << pow(3, 5) << endl;

//  constexpr unsigned int c = pow(3, 5);
//  GCC 4.9.2 error: call to non-constexpr function 'unsigned int pow(unsigned int, unsigned int)'

    cout << "3^5 = " << powr(3, 5) << endl;

//  constexpr unsigned int c = cpow(3, 5);
//  Zou moeten werken in C++14 (nog niet getest omdat GCC 5 nog niet beschikbaar is).

    constexpr unsigned int c = cpowr(3, 5);

    return 0;
}
