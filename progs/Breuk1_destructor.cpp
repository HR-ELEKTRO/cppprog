// Werken met breuken in C++ ... destructor

#include <iostream>
#include <numeric>
#include <cassert>
using namespace std;

// Classdeclaratie:

class Breuk {
public:
    // Classinterface.
    // Vertelt wat je met een object van de class kunt doen.
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    ~Breuk();
    int teller() const;
    int noemer() const;
    void plus(Breuk b);
    void abs();
//  ...
//  Er zijn nog veel uitbreidingen mogelijk.
//  ...
private:
    // Classimplementatie.
    // Vertelt wat je nodig hebt om een object van de class te maken.
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

Breuk::~Breuk() {
    cout << "Een breuk met de waarde " << boven << "/" << onder << " is verwijderd uit het geheugen.\n";
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
}

/* Output:
b1 {4} = 4/1
b2 {23, -5} = -23/5
b3 {b2} = -23/5
b3.abs() = 23/5
b3 = b2 = -23/5
Een breuk met de waarde 5/1 is verwijderd uit het geheugen.
Druk op enter om verder te gaan...
b3.plus(5) = 2/5
Een breuk met de waarde 2/5 is verwijderd uit het geheugen.
Druk op enter om verder te gaan...
Een breuk met de waarde -23/5 is verwijderd uit het geheugen.
Druk op enter om verder te gaan...
Een breuk met de waarde 4/1 is verwijderd uit het geheugen.
Druk op enter om verder te gaan...
*/