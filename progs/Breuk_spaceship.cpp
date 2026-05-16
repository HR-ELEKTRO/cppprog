// Vergelijken van breuken in C++ ... zoals met ints!! een echt UDT

import std;
using namespace std;
#include <cassert>

// UDT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    bool operator==(const Breuk& rechts) const;
    strong_ordering operator<=>(const Breuk& rechts) const;
private:
    // Invariant: Breuken zijn altijd genormaliseerd.
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
};

istream& operator>>(istream& in, Breuk& b);

// UDT-definitie:

Breuk::Breuk(): Breuk{0, 1} {
}

Breuk::Breuk(int t): Breuk{t, 1} {
}

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

bool Breuk::operator==(const Breuk& rechts) const {
    return boven == rechts.boven && onder == rechts.onder;
}

strong_ordering Breuk::operator<=>(const Breuk& rechts) const {
    if (*this == rechts) {
        return strong_ordering::equal;
    }
    if (boven * rechts.onder < rechts.boven * onder) {
        return strong_ordering::less;
    }
    return strong_ordering::greater;
}

// Hoofdprogramma:

int main() {
    Breuk b1, b2;
    print("Geef Breuk (a/b): ");
    cin >> b1;
    print("Geef nog een Breuk (c/d): ");
    cin >> b2;
    if (b1 == b2) {
        println("{} is gelijk aan {}.", b1, b2);
    }
    if (b1 != b2) {
        println("{} is niet gelijk aan {}.", b1, b2);
    }
    if (b1 < b2) {
        println("{} is kleiner dan {}.", b1, b2);
    }
    if (b1 > b2) {
        println("{} is groter dan {}.", b1, b2);
    }
    if (b1 <= b2) {
        println("{} is kleiner dan of gelijk aan {}.", b1, b2);
    }
    if (b1 >= b2) {
        println("{} is groter dan of gelijk aan {}.", b1, b2);
    }
    print("Geef een geheel getal i: ");
    int i;
    cin >> i;
    if (b1 == i) {
        println("{} is gelijk aan {}.", b1, i);
    }
    if (b1 != i) {
        println("{} is niet gelijk aan {}.", b1, i);
    }
    if (b1 < i) {
        println("{} is kleiner dan {}.", b1, i);
    }
    if (b1 > i) {
        println("{} is groter dan {}.", b1, i);
    }
    if (b1 <= i) {
        println("{} is kleiner dan of gelijk aan {}.", b1, i);
    }
    if (b1 >= i) {
        println("{} is groter dan of gelijk aan {}.", b1, i);
    }
    if (i == b2) {
        println("{} is gelijk aan {}.", i, b2);
    }
    if (i != b2) {
        println("{} is niet gelijk aan {}.", i, b2);
    }
    if (i < b2) {
        println("{} is kleiner dan {}.", i, b2);
    }
    if (i > b2) {
        println("{} is groter dan {}.", i, b2);
    }
    if (i <= b2) {
        println("{} is kleiner dan of gelijk aan {}.", i, b2);
    }
    if (i >= b2) {
        println("{} is groter dan of gelijk aan {}.", i, b2);
    }
}
