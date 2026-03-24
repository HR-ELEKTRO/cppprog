// Voorbeeld van het gebruik van reference parameters
import std;
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

    println("i = {}", i);
    println("j = {}", j);

    swap_ints_ptr(&i, &j);

    println("i = {}", i);
    println("j = {}", j);

   swap_ints_ref(i, j);
 
    println("i = {}", i);
    println("j = {}", j);

//  swap_ints_ref(i, 5);
//  Error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
}
