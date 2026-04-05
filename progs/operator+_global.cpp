// Oplossing voor probleem met memberfunctie operator+
// In plaats van 1 member operator+ en 1 globale operator+ kan er ook 
// alleen een globale operator+ gebruikt worden. Zie Breuk3.cpp

import std;
#include <cassert>
using namespace std;

// UDT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    Breuk& operator+=(const Breuk& rechts);
    const Breuk operator+(const Breuk& rechts) const;
    Breuk& operator-=(const Breuk& rechts);
    const Breuk operator-(const Breuk& rechts) const;
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
};

const Breuk operator+(int links, const Breuk& rechts);
const Breuk operator-(int links, const Breuk& rechts);
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

Breuk& Breuk::operator+=(const Breuk& rechts) {
    boven = boven * rechts.onder + onder * rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
}

const Breuk Breuk::operator+(const Breuk& rechts) const {
    Breuk copy_links{*this};
    copy_links += rechts;
    return copy_links;
}

Breuk& Breuk::operator-=(const Breuk& rechts) {
    boven = boven * rechts.onder - onder * rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
}

const Breuk Breuk::operator-(const Breuk& rechts) const {
    Breuk copy_links {*this};
    copy_links -= rechts;
    return copy_links;
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

ostream& operator<<(ostream& out, const Breuk& b) {
    return out << b.boven << '/' << b.onder;
}

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& breuk, auto& context) const {
        ostringstream ss;
        ss << breuk;
        return formatter<string>::format(ss.str(), context);
    }
};

const Breuk operator+(int links, const Breuk& rechts) {
    // optellen is commutatief dus links + rechts is gelijk aan rechts + links
    return rechts + links;
}

const Breuk operator-(int links, const Breuk& rechts) {
    // aftrekken is niet commutatief!
    Breuk copy_links {links};
    copy_links -= rechts;
    return copy_links;
}

// Hoofdprogramma:

int main() {
    Breuk b1 {2, 3}, b2 {4, 5}, b3;
    b3 = b1 + b2;
    println("{} + {} = {}", b1, b2, b3);
    println("{} - {} = {}", b1, b2, b1 - b2);

//  kun je bij een Breuk een int optellen?
    b3 = b1 + 5;
    println("{} + 5 = {}", b1, b3);
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
//  b3 = b1 + Breuk {5};

//  kun je van een Breuk een int aftrekken?
    println("{} - 5 = {}", b1, b1 - 5);
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
    
//  kun je bij een int een Breuk optellen?
    b3 = 5 + b2;
    println("5 + {} = {}", b2, b3);
//  Ja, de globale operator+(int links, const Breuk& rechts) wordt aangeroepen.
//  b3.operator+(5, b2);

//  kun je van een int een Breuk aftrekken?
    println("5 - {} = {}", b2, 5 - b2);
//  Ja, de globale operator-(int links, const Breuk& rechts) wordt aangeroepen.
}
