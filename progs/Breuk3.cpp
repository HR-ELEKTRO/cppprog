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
    Breuk& operator+=(const Breuk& right);
    Breuk& operator++();         // prefix
    const Breuk operator++(int); // postfix
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
friend bool operator==(const Breuk& left, const Breuk& right);
};

istream& operator>>(istream& in, Breuk& b);
bool operator!=(const Breuk& left, const Breuk& right);
const Breuk operator+(const Breuk& left, const Breuk& right);
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

Breuk& Breuk::operator++() {
    boven += onder;
    return *this;
}

const Breuk Breuk::operator++(int) {
    Breuk b(*this);
    ++(*this);
    return b;
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

const Breuk operator+(const Breuk& left, const Breuk& right) {
    Breuk copy_left {left};
    copy_left += right;
    return copy_left;
}

/* verkorte notatie:
const Breuk operator+(const Breuk& left, const Breuk& right) {
    return Breuk {left} += right;
}
*/

/* verkorte notatie:
const Breuk operator+(Breuk left, const Breuk& right) {
    return left += right;
}
*/

ostream& operator<<(ostream& left, const Breuk& right) {
    return left << right.boven << '/' << right.onder;
}

istream& operator>>(istream& left, Breuk& right) {
    int teller;
    if (left >> teller)
        if (left.peek() == '/') {
            left.get();
            int noemer;
            if (left >> noemer) right = Breuk{teller, noemer};
            else right = Breuk{teller};
        }
        else right = Breuk{teller};
    else right = Breuk{};
    return left;
}

bool operator==(const Breuk& left, const Breuk& right) {
    return left.boven == right.boven && left.onder == right.onder;
}

bool operator!=(const Breuk& left, const Breuk& right) {
    return !(left == right);
}

// Hoofdprogramma:

int main() {
    Breuk b1, b2;              // definiëren van variabelen
    cout << "Geef Breuk (a/b): ";
    cin >> b1;                 // inlezen met >>
    cout << "Geef nog een Breuk (c/d): ";
    cin >> b2;                 // inlezen met >>
    cout << b1 << " + " 
         << b2 << " = "        // afdrukken met <<
         << (b1 + b2) << '\n'; // optellen met +
    Breuk b3{18, -12};         // definiëren en initialiseren
    if (b1 != b3) {            // vergelijken met !=
        ++b3;                  // verhogen met ++
    }
    cout << b3 << '\n';        // afdrukken met <<
    b3 += {-5, 2};             // verhogen met +=
    cout << b3 << '\n';        // afdrukken met <<
    if (-3 == b3) {            // vergelijken met een int met ==
        cout << "Ok.\n";
    } 
    else {
        cout << "Error.\n";
    }
}

/* Output:
Geef Breuk (a/b): -1/-2
Geef nog een Breuk (c/d): 3/4
1/2 + 3/4 = 5/4
-1/2
-3/1
Ok.
*/