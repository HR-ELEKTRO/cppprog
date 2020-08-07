// Werken met breuken in C++ ... zoals met ints!! een echt UDT

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
    Breuk& operator+=(Breuk rechts);
    Breuk& operator++();         // prefix
    const Breuk operator++(int); // postfix
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, Breuk b);
friend bool operator==(Breuk links, Breuk rechts);
};

istream& operator>>(istream& in, Breuk& b);
bool operator!=(Breuk links, Breuk rechts);
const Breuk operator+(Breuk links, Breuk rechts);
// ...
// Er zijn nog veel uitbreidingen mogelijk
// ...

// UDT-definitie:

Breuk::Breuk(): Breuk{0, 1} {
}

Breuk::Breuk(int t): Breuk{t, 1} {
}

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

Breuk& Breuk::operator+=(Breuk rechts) {
    boven = boven * rechts.onder + onder * rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator++() {
    boven += onder;
    return *this;
}

const Breuk Breuk::operator++(int) {
    Breuk b{*this};
    ++(*this);
    return b;
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

const Breuk operator+(Breuk links, Breuk rechts) {
    return links += rechts;
}
ostream& operator<<(ostream& out, Breuk b) {
    return out << b.boven << '/' << b.onder;
}

istream& operator>>(istream& in, Breuk& b) {
    int teller;
    if (in >> teller)
        if (in.peek() == '/') {
            in.get();
            int noemer;
            if (in >> noemer) b = Breuk(teller, noemer);
            else b = Breuk(teller);
        }
        else b = Breuk(teller);
    else b = Breuk();
    return in;
}

bool operator==(Breuk links, Breuk rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

bool operator!=(Breuk links, Breuk rechts) {
    return !(links == rechts);
}

// Hoofdprogramma:

int main() {
    Breuk b1, b2;                   // definiëren van variabelen
    cout << "Geef Breuk (a/b): ";
    cin >> b1;                      // inlezen met >>
    cout << "Geef nog een Breuk (c/d): ";
    cin >> b2;                      // inlezen met >>
    cout << b1 << "+" << b2 << "=";  // afdrukken met <<
    cout << (b1 + b2) << '\n';      // optellen met +
    Breuk b3(18, -9);               // definiëren en initialiseren
    if (b1 != b3) {                 // vergelijken met !=
        ++b3;                       // verhogen met ++
    }
    cout << b3 << '\n';             // afdrukken met <<
    b3 += 5;                        // verhogen met +=
    cout << b3 << '\n';             // afdrukken met <<
    if (-2 == b3) {                 // vergelijken met een int met ==
        cout << "Ok.\n";
    } 
    else {
        cout << "Error.\n";
    }
}
