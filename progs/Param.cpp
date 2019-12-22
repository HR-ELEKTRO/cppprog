// call by value en call by reference

#include <iostream>
using namespace std;

// Voorbeeld call by value:
void skip_lines(int l) {
    while (l-- > 0)
        cout << '\n';
}

// Voorveeld call by reference (met behulp van een pointer): 
void swap_ints1(int* p, int* q) {
    int t{*p};
    *p = *q;
    *q = t;
}

// Voorveeld call by reference (met behulp van een reference): 
void swap_ints2(int& p, int& q) {
    int t{p};
    p = q;
    q = t;
}

int main() {
    int n{7};
    cout << "Hallo\n";
    skip_lines(n);
    cout << "daar!\n";
    skip_lines(3);

    int m{3};
    cout << "n = " << n << " m = " << m << '\n';
    swap_ints1(&n, &m);
    cout << "n = " << n << " m = " << m << '\n';
    swap_ints2(n, m);
    cout << "n = " << n << " m = " << m << '\n';

//  swap_ints2(n, 5);
//  Error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
}
