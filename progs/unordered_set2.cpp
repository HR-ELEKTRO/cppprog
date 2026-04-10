import std;
#include <cassert>
using namespace std;

class Breuk;

namespace std
{
    template<> struct hash<Breuk> {
        size_t operator()(Breuk const& h) const noexcept;
    };
}

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
friend bool operator==(const Breuk& links, const Breuk& rechts);
friend size_t hash<Breuk>::operator()(Breuk const& h) const noexcept;
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
    int d {gcd(boven < 0 ? -boven : boven, onder)};
    boven /= d;
    onder /= d;
}

ostream& operator<<(ostream& out, const Breuk& b) {
    return out << b.boven << '/' << b.onder;
}

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& b, auto& context) const {
        ostringstream ss;
        ss << b;
        return formatter<string>::format(ss.str(), context);
    }
};

bool operator==(const Breuk& links, const Breuk& rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

namespace std
{
    size_t hash<Breuk>::operator()(Breuk const& b) const noexcept {
        return hash<int>{}(b.boven) ^ hash<int>{}(b.onder);
    }
}

int main() {
    unordered_set<Breuk> breuken;
    breuken.insert(Breuk {1,2});
    breuken.insert(Breuk {1,3});
    breuken.insert(Breuk {2,3});
    breuken.insert(Breuk {1,4});
    breuken.insert(Breuk {2,4});
    breuken.insert(Breuk {3,4});
    println("breuken = {::s}", breuken);
}
