// Voorbeeld van het gebruik van reference parameters
#include <iostream>
using namespace std;

// swap_ints in C-style:

void swap_ints_ptr(int* p, int* q) {
    int t = *p;
    *p = *q;
    *q = t;
}

// swap_ints in C++-style:

void swap_ints_ref(int& p, int& q) {
    int t {p};
    p = q;
    q = t;
}

int main() {
    int i {3};
    int j {4};

    cout << "i = " << i << '\n';
    cout << "j = " << j << '\n';

    swap_ints_ptr(&i, &j);

    cout << "i = " << i << '\n';
    cout << "j = " << j << '\n';

   swap_ints_ref(i, j);
 
    cout << "i = " << i << '\n';
    cout << "j = " << j << '\n';

//  swap_ints_ref(i, 5);
//  Error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
}
