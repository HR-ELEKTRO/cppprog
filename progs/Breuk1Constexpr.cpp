// Werken met breuken in C++ ... constructor, const memberfuncties

#include <iostream>
#include <cassert>
using namespace std;

// Classdeclaratie:

class Breuk {
public:
    // Classinterface. Vertelt:
    // - hoe je een object van deze class kunt maken;
    // - wat je aan een object van deze class kunt vragen;
    // - wat je met een object van de class kunt doen.
    constexpr Breuk();
    constexpr Breuk(int t);
    constexpr Breuk(int t, int n);
    constexpr int teller() const;
    constexpr int noemer() const;
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
    constexpr void normaliseer();
};

// Hulpfunctie: bepaald de grootste gemene deler.

constexpr int ggd(int n, int m) {
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

constexpr Breuk::Breuk(): boven(0), onder(1) {
}

constexpr Breuk::Breuk(int t): boven(t), onder(1) {
}

constexpr Breuk::Breuk(int t, int n): boven(t), onder(n) {
    normaliseer();
}

constexpr int Breuk::teller() const {
    return boven;
}

constexpr int Breuk::noemer() const {
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

constexpr void Breuk::normaliseer() {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d = ggd(boven, onder);
    boven /= d;
    onder /= d;
}

// Hoofdprogramma:

int main() {
    Breuk b1{4};
    cout << "b1{4} = " << b1.teller() << '/' << b1.noemer() << '\n';
    Breuk b2{23, -5};
    cout << "b2{23, -5} = " << b2.teller() << '/' << b2.noemer() << '\n';
    Breuk b3{b2};
    cout << "b3{b2} = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3.abs();
    cout << "b3.abs() = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3 = b2;
    cout << "b3 = b2 = " << b3.teller() << '/' << b3.noemer() << '\n';
    b3.plus(5);
    cout << "b3.plus(5) = " << b3.teller() << '/' << b3.noemer() << '\n';

    constexpr Breuk halve{1, 2};
    cout << "halve = " << halve.teller() << '/' << halve.noemer() << '\n';

//  halve = b3;
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

//  halve.plus(b3);
//  Error: passing ‘const Breuk’ as ‘this’ argument discards qualifiers

    b3 = halve;
    cout << "b3 = halve = " << b3.teller() << '/' << b3.noemer() << '\n';
}

/* Output:
b1{4} = 4/1
b2{23, -5} = -23/5
b3{b2} = -23/5
b3.abs() = 23/5
b3 = b2 = -23/5
b3.plus(5) = 2/5
halve = 1/2
b3 = halve = 1/2
*/