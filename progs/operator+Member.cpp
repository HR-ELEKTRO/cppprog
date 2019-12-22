// Probleem met memberfunctie operator+
// Zie operator+Global voor een oplossing voor dit probleem

#include <iostream>
#include <cassert>
using namespace std;

// ADT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    Breuk& operator+=(const Breuk& right);
    const Breuk operator+(const Breuk& right) const;
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
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

// ADT-definitie:

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
    Breuk copy_left{*this}; // maak een kopietje van de receiver
    copy_left += right;     // tel daar het object right bij op
    return copy_left;       // geef deze waarde terug
}

/* verkorte notatie:
const Breuk Breuk::operator+(const Breuk& right) const {
    return copy_left(*this) += right;
}
*/

void Breuk::normaliseer() {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d{ggd(boven, onder)};
    boven /= d;
    onder /= d;
}


ostream& operator<<(ostream& left, const Breuk& right) {
    return left << right.boven << '/' << right.onder;
}

// Hoofdprogramma:

int main() {
    Breuk b1{2, 3}, b2{4, 5}, b3;
    b3 = b1 + b2;
    cout << b1 << " + " << b2 << " = " << b3 << endl;

//  kun je bij een Breuk een int optellen?
    b3 = b1 + 5;
    cout << b1 << " + 5 = " << b3 << endl;
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
//  b3 = b1 + Breuk(5);

//  kun je bij een int een Breuk optellen?
//  b3 = 5 + b2;
//  cout << "5 + " << b2 << " = " << b3 << endl;
//  Nee
//  Error: no match for ‘operator+’ (operand types are ‘int’ and ‘Breuk’)
//  Zie operator+Global voor een oplossing voor dit probleem
}
