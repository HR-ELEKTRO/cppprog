// Werken met breuken in C++ ... operator overloading

#include <iostream>
#include <cassert>
using namespace std;

// Classdeclaratie.

class Breuk {
public:
    Breuk(int t, int n);
    int teller() const;
    int noemer() const;
    void operator+=(Breuk right);
//  ...
//  Er zijn nog veel uitbreidingen mogelijk
//  ...
private:
    int boven;
    int onder;
    void normaliseer();
};

// Hulpfunctie: bepaald de grootste gemene deler.

int ggd(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != n)
        if (n > m) n -= m;
        else m -= n;
    return n;
}

// Classdefinitie:

Breuk::Breuk(int t, int n): boven(t), onder(n) {
    normaliseer();
}

int Breuk::teller() const {
    return boven;
}

int Breuk::noemer() const {
    return onder;
}

void Breuk::operator+=(Breuk right) {
    boven = boven * right.onder + onder * right.boven;
    onder *= right.onder;
    normaliseer();
}

void Breuk::normaliseer() {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d(ggd(boven, onder));
    boven /= d;
    onder /= d;
    // controle of nog steeds aan de invariant van de class wordt voldaan:
    assert(onder > 0 && ggd(boven, onder) == 1);
}

// Hoofdprogramma:

int main() {
    Breuk b1(14, 4);
    cout << "b1(14, 4) = " << b1.teller() << '/' << b1.noemer() << endl;
    Breuk b2(23, -5);
    cout << "b2(23, -5) = " << b2.teller() << '/' << b2.noemer() << endl;
    b1 += b2;
    cout << "b1 += b2 = " << b1.teller() << '/' << b1.noemer() << endl;

//  "Rijgen" van de operator += is nu niet mogelijk
//  b1 += b1 += b2;
//  Error (Microsoft): binary '+=' : no operator found which takes a right-hand operand of type 'void' (or there is no acceptable conversion)
//  Error (GCC):       no match for 'operator+=' in 'b1 += b1.Breuk::operator+=(b2)'
//  Zie breuk3.cpp voor de oplossing van dit probleem

    cin.get();
    return 0;
}

/* Output:
b1(14, 4) = 7/2
b2(23, -5) = -23/5
b1 += b2 = -11/10
*/


