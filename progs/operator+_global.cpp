// Oplossing voor probleem met memberfunctie operator+
// In plaats van 1 member operator+ en 1 globale operator+ kan er ook 
// alleen een globale operator+ gebruikt worden. Zie Breuk3.cpp

#include <iostream>
#include <numeric>
#include <cassert>
using namespace std;

// UDT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    Breuk& operator+=(const Breuk& right);
    const Breuk operator+(const Breuk& right) const;
    Breuk& operator-=(const Breuk& right);
    const Breuk operator-(const Breuk& right) const;
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
};

const Breuk operator+(int left, const Breuk& right);
const Breuk operator-(int left, const Breuk& right);
// ...
// Er zijn nog veel uitbreidingen mogelijk
// ...

// UDT-definitie:

Breuk::Breuk(): boven{0}, onder{1} {
}

Breuk::Breuk(int t): boven{t}, onder{1} {
}

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

Breuk& Breuk::operator+=(const Breuk& right) {
    boven = boven * right.onder + onder * right.boven;
    onder *= right.onder;
    normaliseer();
    return *this;
}

const Breuk Breuk::operator+(const Breuk& right) const {
    Breuk copy_left{*this};
    copy_left += right;
    return copy_left;
}

Breuk& Breuk::operator-=(const Breuk& right) {
    boven = boven * right.onder - onder * right.boven;
    onder *= right.onder;
    normaliseer();
    return *this;
}

const Breuk Breuk::operator-(const Breuk& right) const {
    Breuk copy_left {*this};
    copy_left -= right;
    return copy_left;
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

ostream& operator<<(ostream& left, const Breuk& right) {
    return left << right.boven << '/' << right.onder;
}

const Breuk operator+(int left, const Breuk& right) {
    // optellen is commutatief dus left + right is gelijk aan right + left
    return right + left;
}

const Breuk operator-(int left, const Breuk& right) {
    // aftrekken is niet commutatief!
    Breuk copy_left {left};
    copy_left -= right;
    return copy_left;
}

// Hoofdprogramma:

int main() {
    Breuk b1 {2, 3}, b2 {4, 5}, b3;
    b3 = b1 + b2;
    cout << b1 << " + " << b2 << " = " << b3 << '\n';
    cout << b1 << " - " << b2 << " = " << b1 - b2 << '\n';
    
//  kun je bij een Breuk een int optellen?
    b3 = b1 + 5;
    cout << b1 << " + 5 = " << b3 << '\n';
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
//  b3 = b1 + Breuk {5};

//  kun je van een Breuk een int aftrekken?
    cout << b1 << " - 5 = " << b1 - 5 << '\n';
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
    
//  kun je bij een int een Breuk optellen?
    b3 = 5 + b2;
    cout << "5 + " << b2 << " = " << b3 << '\n';
//  Ja, de globale operator+(int left, const Breuk& right) wordt aangeroepen.
//  b3.operator+(5, b2);

//  kun je van een int een Breuk aftrekken?
    cout << "5 - " << b2 << " = " << 5 - b2 << '\n';
//  Ja, de globale operator-(int left, const Breuk& right) wordt aangeroepen.
}
