import std;
#include <cassert>
using namespace std;

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    int teller() const;
    int noemer() const;
//  ...
//  Er zijn nog veel uitbreidingen mogelijk.
//  ...
private:
    int boven {0}; // directe initialisatie
    int onder {1}; // directe initialisatie
    void normaliseer();
};

Breuk::Breuk() { // geen initialization list 
}

Breuk::Breuk(int t): boven{t} { // de datamember onder wordt niet in de initialization list geïnitialiseerd
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

int main() {
    Breuk b1;
    println("b1 = {}/{}", b1.teller(), b1.noemer());
    Breuk b2 {4};
    println("b2 {{4}} = {}/{}", b2.teller(), b2.noemer());
    Breuk b3 {23, -5};
    println("b3 {{23, -5}} = {}/{}", b3.teller(), b3.noemer());
}

/*
Uitvoer:
b1 = 0/1
b2 {4} = 4/1
b3 {23, -5} = -23/5
*/