import std;
#include <cassert>
using namespace std;

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    int boven;
    int onder;
    friend struct std::formatter<Breuk>;
};

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d {gcd(boven, onder)};
    boven /= d;
    onder /= d;
}

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& breuk, auto& context) const {
        return formatter<string>::format(to_string(breuk.boven)+"/"+to_string(breuk.onder), context);
    }
};

int main() {
    Breuk b {30, 94};
    println("Breuk b = {}", b);
    println("Breuk b = {:_^16}", b);
    // println("Breuk breuk = {:0X}", breuk);
}