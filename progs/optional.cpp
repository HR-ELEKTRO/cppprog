// Inlezen van breuken in C++ m.b.v. optional

import std;
using namespace std;
#include <cassert>

// UDT-declaratie:

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    void print() const;
    void println() const;
private:
    // Invariant: Breuken zijn altijd genormaliseerd.
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, Breuk b);
};

optional<Breuk> leesin();

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

void Breuk::print() const {
    std::print("{}/{}", boven, onder);
}

void Breuk::println() const {
    print();
    std::println("");
}

optional<Breuk> leesin() {
    int teller;
    if (cin >> teller) {
        while (iswspace(cin.peek())) {
            cin.get();
        }
        if (cin.peek() == '/') {
            cin.get();
            int noemer;
            if (cin >> noemer && noemer != 0 && iswspace(cin.peek())) {
                return Breuk(teller, noemer);
            }
            return {}; // or return nullopt;
        }
        if (iswspace(cin.peek())) {
            return Breuk(teller);
        }
    }
    return {};
}

// Hoofdprogramma:

int main() {
    Breuk b1, b2;
    print("Geef Breuk (a/b): ");
    auto r1 = leesin();
    while (!r1.has_value()) {
        print("Ongeldige invoer. Probeer opnieuw: ");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        r1 = leesin();
    }
    b1 = r1.value();
    b1.println();
    
    print("Geef nog een Breuk (c/d): ");
    auto r2 = leesin();
    while (!r2) {
        print("Ongeldige invoer. Probeer opnieuw: ");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        r2 = leesin();
    }
    b2 = *r2;
    b2.println();
}
