import std;
#include <cassert>
using namespace std;

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
    bool operator==(const Breuk& rechts) const = default;
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
    Breuk b1 {2, 1};
    Breuk b2 {-4, -2};
    assert(b1 == b2);
    assert(!(b1 != b2));
    assert(b1 == 2);
    assert(2 == b1);
    assert(b1 != 3);
    assert(3 != b1);
    println("Alle testen zijn geslaagd.");
}
