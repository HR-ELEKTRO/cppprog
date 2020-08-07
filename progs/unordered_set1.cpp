#include <iostream>
#include <cassert>
#include <numeric>
#include <unordered_set>
using namespace std;

class Breuk;

struct Breuk_hash {   
    size_t operator()(Breuk const& b) const noexcept;
};

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
friend bool operator==(const Breuk& links, const Breuk& rechts);
friend size_t Breuk_hash::operator()(Breuk const& b) const noexcept;
};

bool operator!=(const Breuk& links, const Breuk& rechts);

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
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

ostream& operator<<(ostream& out, const Breuk& b) {
    return out << b.boven << '/' << b.onder;
}

bool operator==(const Breuk& links, const Breuk& rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

bool operator!=(const Breuk& links, const Breuk& rechts) {
    return !(links == rechts);
}

size_t Breuk_hash::operator()(Breuk const& b) const noexcept {
    return hash<int>{}(b.boven) ^ hash<int>{}(b.onder);
}

int main() {
    unordered_set<Breuk, Breuk_hash> breuken;
    breuken.insert(Breuk {1,2});
    breuken.insert(Breuk {1,3});
    breuken.insert(Breuk {2,3});
    breuken.insert(Breuk {1,4});
    breuken.insert(Breuk {2,4});
    breuken.insert(Breuk {3,4});
    for (auto b: breuken) {
        cout << b << '\n';
    }
}
