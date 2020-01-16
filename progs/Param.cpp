// call by value en call by reference

#include <iostream>
using namespace std;

// Voorbeeld call by value:
void skip_lines(int l) {
    while (--l > 0)
        cout << '\n';
}

// Voorveeld call by reference (met behulp van een pointer): 
void swap_ints_ptr(int* p, int* q) {
    int t {*p};
    *p = *q;
    *q = t;
}

// Voorveeld call by reference (met behulp van een reference): 
void swap_ints_ref(int& p, int& q) {
    int t {p};
    p = q;
    q = t;
}

int main() {
    int n {7};
    cout << "Hallo\n";
//  Aanroep call by value met een variabele
    skip_lines(n);
    cout << "daar!\n";
//  De variabele n is niet veranderd
    cout << "n = " << n << '\n';
//  Aanroep call by value met een getal
    skip_lines(3);

    int m {3};
    cout << "n = " << n << " m = " << m << '\n';
//  Aanroep call by reference (met behulp van een pointer) met variabelen
    swap_ints_ptr(&n, &m);
//  De inhoud van de variabelen n en m is verwisseld
    cout << "n = " << n << " m = " << m << '\n';
//  Aanroep call by reference (met behulp van een reference) met variabelen
    swap_ints_ref(n, m);
//  De inhoud van de variabelen n en m is verwisseld
    cout << "n = " << n << " m = " << m << '\n';

//  Aanroep call by reference (met behulp van een pointer) met een getal
//  swap_ints2(n, 5);
//  Error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
}
