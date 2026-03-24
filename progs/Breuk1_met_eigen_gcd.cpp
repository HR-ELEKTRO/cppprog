// Werken met breuken in C++ ... constructor, const memberfuncties pre C++17

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

// Classdeclaratie:

class Breuk {
public:
    // Classinterface. Vertelt:
    // - hoe je een object van deze class kunt maken;
    // - wat je aan een object van deze class kunt vragen;
    // - wat je met een object van de class kunt doen.
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    int teller() const;
    int noemer() const;
    void plus(Breuk b);
    void abs();
    // ...
    // Er zijn nog veel uitbreidingen mogelijk.
    // ...
private:
    // Classimplementatie. Vertelt:
    // - wat je nodig hebt om een object van de class te maken.
    // Dit is voor gebruikers van de class niet van belang.
    int boven;
    int onder;
    void normaliseer();
};

// Hulpfuncties:
int gcd_r(int n, int m) {
    return m == 0 ? n: gcd_r(m, n % m); 
}

int gcd(int n, int m) {
    return gcd_r(abs(m), abs(n)); 
}

// Classdefinitie:
// Vertelt hoe de memberfuncties van de class geïmplenteerd zijn.
// Dit is voor gebruikers van de class niet van belang.

Breuk::Breuk(): boven{0}, onder{1} {
}

Breuk::Breuk(int t): boven{t}, onder{1} {
}

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

int Breuk::teller() const {
    return boven;
}

int Breuk::noemer() const {
    return onder;
}

void Breuk::plus(Breuk b) {
    boven = boven * b.onder + onder * b.boven;
    onder *= b.onder;
    normaliseer();
}

void Breuk::abs() {
    if (boven < 0) 
        boven = -boven;
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
}

// Hoofdprogramma:

int main() {
    Breuk b1 {4};
    cout << "b1 {4} = " << b1.teller() << '/' << b1.noemer() << '\n';
    Breuk b2 {23, -5};
    cout << "b2 {23, -5} = " << b2.teller() << '/' << b2.noemer() << '\n';
    Breuk b3 {b2};
    cout << "b3 {b2} = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3.abs();
    cout << "b3.abs() = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3 = b2;
    cout << "b3 = b2 = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3.plus(5);
    cout << "b3.plus(5) = " << b3.teller() << '/' << b3.noemer() << '\n';

    const Breuk halve{1, 2};
    cout << "halve = " << halve.teller() << '/' << halve.noemer() << '\n';

//  halve = b3;
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

//  halve.plus(b3);
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

    b3 = halve;
    cout << "b3 = halve = " << b3.teller() << '/' << b3.noemer() << '\n';
}

/* Output:
b1 {4} = 4/1
b2 {23, -5} = -23/5
b3 {b2} = -23/5
b3.abs() = 23/5
b3 = b2 = -23/5
b3.plus(5) = 2/5
halve = 1/2
b3 = halve = 1/2
*/