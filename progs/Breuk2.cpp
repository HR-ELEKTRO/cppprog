// Werken met breuken in C++ ... operator overloading

#include <iostream>
#include <numeric>
#include <cassert>
using namespace std;

// Classdeclaratie:

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

// Classdefinitie:

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
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
    int d {gcd(boven < 0 ? -boven : boven, onder)};
    boven /= d;
    onder /= d;
    // controle of nog steeds aan de invariant van de class wordt voldaan:
    assert(onder > 0 && gcd(boven, onder) == 1);
}

// Hoofdprogramma:

int main() {
    Breuk b1 {14, 4};
    cout << "b1 {14, 4} = " << b1.teller() << '/' << b1.noemer() << '\n';
    Breuk b2 {23, -5};
    cout << "b2 {23, -5} = " << b2.teller() << '/' << b2.noemer() << '\n';
    b1 += b2;
    cout << "b1 += b2 = " << b1.teller() << '/' << b1.noemer() << '\n';

//  "Rijgen" van de operator += is nu niet mogelijk
//  b1 += b1 += b2;
//  Error: no match for ‘operator+=’ (operand types are ‘Breuk’ and ‘void’)
//  Zie breuk3.cpp voor de oplossing van dit probleem
}

/* Output:
b1 {14, 4} = 7/2
b2 {23, -5} = -23/5
b1 += b2 = -11/10
*/


