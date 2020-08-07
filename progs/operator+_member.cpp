// Probleem met memberfunctie operator+
// Zie operator+Global voor een oplossing voor dit probleem

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
    Breuk& operator+=(const Breuk& rechts);
    const Breuk operator+(const Breuk& rechts) const;
    // ...
    // Er zijn nog veel uitbreidingen mogelijk
    // ...
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
};

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
    Breuk copy_links {*this}; // maak een kopietje van de receiver
    copy_links += rechts;     // tel daar het object rechts bij op
    return copy_links;       // geef deze waarde terug
}

/* verkorte notatie:
const Breuk Breuk::operator+(const Breuk& rechts) const {
    return copy_links {*this} += rechts;
}
*/

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

// Hoofdprogramma:

int main() {
    Breuk b1 {2, 3}, b2 {4, 5}, b3;
    b3 = b1 + b2;
    cout << b1 << " + " << b2 << " = " << b3 << '\n';

//  kun je bij een Breuk een int optellen?
    b3 = b1 + 5;
    cout << b1 << " + 5 = " << b3 << '\n';
//  Ja, de int wordt omgezet in een Breuk met de constructor Breuk::Breuk(int t)
//  b3 = b1 + Breuk(5);

//  kun je bij een int een Breuk optellen?
//  b3 = 5 + b2;
//  cout << "5 + " << b2 << " = " << b3 << '\n';
//  Nee
//  Error: no match for ‘operator+’ (operand types are ‘int’ and ‘Breuk’)
//  Zie operator+_global voor een oplossing voor dit probleem
}
