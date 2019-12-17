// Werken met breuken in C++ ... destructor

#include <iostream>
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
// Vertelt hoe de memberfuncties van de class geïmplenteerd zijn.
// Dit is voor gebruikers van de class niet van belang.

Breuk::Breuk(): boven(0), onder(1) {
}

Breuk::Breuk(int t): boven(t), onder(1) {
}

Breuk::Breuk(int t, int n): boven(t), onder(n) {
    normaliseer();
}

Breuk::~Breuk() {
    cout << "Een breuk met de waarde " << boven << "/" << onder << " is verwijderd uit het geheugen." << endl;
    cout << "Druk op enter om verder te gaan..." << endl;
    cin.get();
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
    if (boven < 0) boven = -boven;
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
}

// Hoofdprogramma:

int main() {
    Breuk b1(4);
    cout << "b1(4) = " << b1.teller() << '/' << b1.noemer() << endl;
    Breuk b2(23, -5);
    cout << "b2(23, -5) = " << b2.teller() << '/' << b2.noemer() << endl;
    Breuk b3(b2);
    cout << "b3(b2) = " << b3.teller() << '/' << b3.noemer() << endl;
    b3.abs();
    cout << "b3.abs() = " << b3.teller() << '/' << b3.noemer() << endl;
    b3 = b2;
    cout << "b3 = b2 = " << b3.teller() << '/' << b3.noemer() << endl;
    b3.plus(5);
    cout << "b3.plus(5) = " << b3.teller() << '/' << b3.noemer() << endl;
    cin.get();
    return 0;
}
