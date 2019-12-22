#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Hond {
public:
    Hond(string n): _naam{n} {
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

bool operator==(const Hond& left, const Hond& right) {
    return left.naam() == right.naam();
}

namespace std
{
    template<> struct hash<Hond>
    {
        size_t operator()(Hond const& h) const noexcept
        {
            return hash<string>{}(h.naam());
        }
    };
}

int main() {
    unordered_map<Hond, int> hondenTeller;
    hondenTeller[Hond{"Fikkie"}] = 3;
    hondenTeller[Hond{"Boris"}] = 5;
    for (auto ht: hondenTeller) {
        cout << ht.first.naam() << " = " << ht.second << '\n';
        ht.first.blaf();
    }
}