import std;
#include <cassert>
using namespace std;

class Tijdsduur {
public:  
    Tijdsduur(unsigned u, unsigned m) : uren{u}, minuten{m} {
        if (minuten >= 60) {
            uren += minuten / 60;
            minuten = minuten % 60;
        }
    }
    auto operator<=>(const Tijdsduur&) const = default;
private:
    unsigned uren;
    unsigned minuten;
};

int main() {
    Tijdsduur t1{1, 30};
    Tijdsduur t2{2, 15};
    Tijdsduur t3{0, 90};
    assert(t1 < t2);
    assert(t1 == t3);
    assert(t2 > t3);
    assert(t1 != t2);
    assert(t1 <= t3);
    assert(t2 >= t3);
    assert(t1 <= t2);
    assert(t2 >= t1);
    assert(t3 >= t1);
    println("Alle tests zijn geslaagd.");
}