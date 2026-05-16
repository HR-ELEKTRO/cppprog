// Let op! De default operator<=> werkt niet correct voor de class Breuk

import std;
using namespace std;
#include <cassert>

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
    strong_ordering operator<=>(const Breuk& rechts) const = default;
private:
    // Invariant: Breuken zijn altijd genormaliseerd.
    int boven;
    int onder;
    void normaliseer();
};

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

int main() {
    Breuk b1 {3, 8};
    Breuk b2 {1, 2};
    assert(b1 != b2);
    assert(b1 < b2);
    println("Alle tests zijn geslaagd");
}
