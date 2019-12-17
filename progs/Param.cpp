// call by value en call by reference

#include <iostream>
using namespace std;

// Voorbeeld call by value:
void skipLines(int l) {
    while (l-- > 0)
        cout << endl;
}

// Voorveeld call by reference (met behulp van een pointer): 
void swapInts1(int* p, int* q) {
    int t(*p);
    *p = *q;
    *q = t;
}

// Voorveeld call by reference (met behulp van een reference): 
void swapInts2(int& p, int& q) {
    int t(p);
    p = q;
    q = t;
}

int main() {
    int n(7);
    cout << "Hallo" << endl;
    skipLines(n);
    cout << "daar!" << endl;
    skipLines(3);

    int m(3);
    cout << "n = " << n << " m = " << m << endl;
    swapInts1(&n, &m);
    cout << "n = " << n << " m = " << m << endl;
    swapInts2(n, m);
    cout << "n = " << n << " m = " << m << endl;

//  swapInts2(n, 5);
//  [C++ Error (Microsoft)]: 'swapInts2' : cannot convert parameter 2 from 'int' to 'int &'
//  [C++ Error (GCC)]:       invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'

    cin.get();
    return 0;
}
