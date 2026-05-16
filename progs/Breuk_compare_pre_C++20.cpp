// Vergelijken van breuken in C++ pre C++20
// In C++20 en later kan dit veel eenvoudiger door de 
// default |operator==| te gebruiken en de operator<=> te overloaden.

import std;
#include <cassert>
using namespace std;

// UDT-declaratie:

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    // Invariant: Breuken zijn altijd genormaliseerd.
    int boven;
    int onder;
    void normaliseer();
    // De vergelijkingsoperatoren worden als globale functies gedefinieerd,
    // zodat er impliciete conversies mogelijk zijn voor beide argumenten.
    friend bool operator==(const Breuk& links, const Breuk& rechts);
    friend bool operator<(const Breuk& links, const Breuk& rechts);
};

// De volgende vergelijkingsoperatoren worden gedefinieerd in termen van operator== en operator<, zodat er maar twee operatoren als friend hoeven te worden geïmplementeerd.
bool operator!=(const Breuk& links, const Breuk& rechts);
bool operator>(const Breuk& links, const Breuk& rechts);
bool operator<=(const Breuk& links, const Breuk& rechts);
bool operator>=(const Breuk& links, const Breuk& rechts);

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
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

bool operator==(const Breuk& links, const Breuk& rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

bool operator!=(const Breuk& links, const Breuk& rechts) {
    return !(links == rechts);
}

bool operator<(const Breuk& links, const Breuk& rechts) {
    return links.boven * rechts.onder < rechts.boven * links.onder;
}

bool operator>(const Breuk& links, const Breuk& rechts) {
    return rechts < links;
}

bool operator<=(const Breuk& links, const Breuk& rechts) {
    return !(links > rechts);
}

bool operator>=(const Breuk& links, const Breuk& rechts) {
    return !(links < rechts);
}

// Hoofdprogramma:

int main() {
    Breuk b1 {2, 1};
    Breuk b2 {-4, -2};
    Breuk b3 {10, 4};

    assert(b1 == b2);
    assert(b1 != b3);
    assert(b1 < b3);
    assert(b3 > b1);
    assert(b1 <= b2);
    assert(b1 <= b3);
    assert(b3 >= b1);
    assert(b3 >= b2);
    assert(b1 == 2);
    assert(2 == b1);
    assert(b1 != 3);
    assert(3 != b1);
    assert(b1 < 3);
    assert(3 > b1);
    assert(b1 <= 2);
    assert(2 <= b1);
    assert(b1 >= 2);
    assert(2 >= b1);
    println("Alle tests zijn geslaagd.");
}
