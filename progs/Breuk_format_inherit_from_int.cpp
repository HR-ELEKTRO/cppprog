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
struct std::formatter<Breuk>: public formatter<int> {
    auto format(const Breuk& breuk, auto& context) const {
        context.advance_to(formatter<int>::format(breuk.boven, context));
        context.advance_to(format_to(context.out(), "/"));
        return formatter<int>::format(breuk.onder, context);
    }
};

int main() {
    Breuk b {30, 94};
    println("Breuk b = {}", b);
    println("Breuk b = {:#0X}", b);
    println("Breuk b = {:#0b}", b);
    // Uitlijnen werkt niet zoals verwacht:
    println("Breuk b = {:_^16}", b);
}

/*
Output:
Breuk b = 15/47
Breuk b = 0XF/0X2F
Breuk b = 0b1111/0b101111
Breuk b = _______15_______/_______47_______
*/