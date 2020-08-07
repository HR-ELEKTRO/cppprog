#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Hond {
public:
    Hond(const string& n): _naam{n} {
    }
    void blaf() const {
        cout << _naam << " zegt: Woef woef!\n";
    }
    string naam() const {
        return _naam;
    }
private:
    string _naam;
};

struct Breuk {
    int boven;
    int onder;
};

bool operator==(const Hond& links, const Hond& rechts) {
    return links.naam() == rechts.naam();
}

struct Hond_hash {
    size_t operator()(Hond const& h) const noexcept
    {
        return hash<string>{}(h.naam());
    }
};

bool operator==(const Breuk& links, const Breuk& rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

struct Breuk_hash {
    size_t operator()(Breuk const& b) const noexcept
    {
        return hash<int>{}(b.boven) ^ hash<int>{}(b.onder);
    }
};

int main() {
    unordered_map<Hond, int,  Hond_hash> honden_teller;
    honden_teller[Hond{"Fikkie"}] = 3;
    honden_teller[Hond{"Boris"}] = 5;
    for (auto ht: honden_teller) {
        cout << ht.first.naam() << " = " << ht.second << '\n';
        ht.first.blaf();
    }
    unordered_map<Breuk, string, Breuk_hash> breuk_naam;
    breuk_naam[Breuk{1,2}] = "half";
    breuk_naam[Breuk{1,3}] = "derde";
    breuk_naam[Breuk{1,4}] = "kwart";
    for (auto bn: breuk_naam) {
        cout << bn.first.boven << '/' << bn.first.onder << " = " << bn.second << '\n';
    }
}
