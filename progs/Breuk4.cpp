// Werken met breuken in C++ ... zoals met ints!! een echt ADT

#include <iostream>
#include <cassert>
using namespace std;

// ADT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    Breuk& operator+=(Breuk right);
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
friend bool operator==(Breuk left, Breuk right);
};

istream& operator>>(istream& in, Breuk& b);
bool operator!=(Breuk left, Breuk right);
const Breuk operator+(Breuk left, Breuk right);
// ...
// Er zijn nog veel uitbreidingen mogelijk
// ...

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

// ADT-definitie:

Breuk::Breuk(): Breuk{0, 1} {
}

Breuk::Breuk(int t): Breuk{t, 1} {
}

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

Breuk& Breuk::operator+=(Breuk right) {
    boven = boven * right.onder + onder * right.boven;
    onder *= right.onder;
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
    int d { ggd(boven, onder) };
    boven /= d;
    onder /= d;
}

const Breuk operator+(Breuk left, Breuk right) {
    return left += right;
}
ostream& operator<<(ostream& left, Breuk right) {
    return left << right.boven << '/' << right.onder;
}

istream& operator>>(istream& left, Breuk& right) {
    int teller;
    if (left >> teller)
        if (left.peek() == '/') {
            left.get();
            int noemer;
            if (left >> noemer) right = Breuk(teller, noemer);
            else right = Breuk(teller);
        }
        else right = Breuk(teller);
    else right = Breuk();
    return left;
}

bool operator==(Breuk left, Breuk right) {
    return left.boven == right.boven && left.onder == right.onder;
}

bool operator!=(Breuk left, Breuk right) {
    return !(left == right);
}

// Hoofdprogramma:

int main() {
    Breuk b1, b2;                   // definiëren van variabelen
    cout << "Geef Breuk: ";
    cin >> b1;                      // inlezen met >>
    cout << "Geef nog een Breuk: ";
    cin >> b2;                      // inlezen met >>
    cout << b1 << "+" << b2 << "=";  // afdrukken met <<
    cout << (b1 + b2) << endl;      // optellen met +
    Breuk b3(18, -9);               // definiëren en initialiseren
    if (b1 != b3) {                 // vergelijken met !=
        b3++;                       // verhogen met ++
    }
    cout << b3 << endl;             // afdrukken met <<
    b3 += 5;                        // verhogen met +=
    cout << b3 << endl;             // afdrukken met <<
    if (-2 == b3) {                 // vergelijken met een int met ==
        cout << "OK." << endl;
    } 
    else {
        cout << "Error." << endl;
    }
}
