// Werken met breuken in C++ ... constructor, const memberfuncties

import std;
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
    int d {gcd(boven, onder)};
    boven /= d;
    onder /= d;
}

// Hoofdprogramma:

int main() {
    Breuk b1 {4};
    println("b1 {{4}} = {}/{}", b1.teller(), b1.noemer());
    Breuk b2 {23, -5};
    println("b2 {{23, -5}} = {}/{}", b2.teller(), b2.noemer());
    Breuk b3 {b2};
    println("b3 {{b2}} = {}/{}", b3.teller(), b3.noemer());
    b3.abs();
    println("b3.abs() = {}/{}", b3.teller(), b3.noemer());
    b3 = b2;
    println("b3 = b2 = {}/{}", b3.teller(), b3.noemer());
    b3.plus(5);
    println("b3.plus(5) = {}/{}", b3.teller(), b3.noemer());

    const Breuk halve{1, 2};
    println("halve = {}/{}", halve.teller(), halve.noemer());

//  halve = b3;
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

//  halve.plus(b3);
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

    b3 = halve;
    println("b3 = halve = {}/{}", b3.teller(), b3.noemer());
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