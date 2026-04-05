import std;
#include <cassert>
using namespace std;

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    int boven;
    int onder;
friend ostream& operator<<(ostream& out, const Breuk& b);
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

int main() {
    Breuk b(30, 94);
    println("b = {}", b);
    println("{:>8}", "b =");
    println("{:>8}", b);
    println("{:?}", "b =");
    println("{:?}", b);
    println("{:_^16}", "b =");
    println("{:_^16}", b);
}

/* Output:
b = 15/47
     b =
   15/47
"b ="
"15/47"
______b =_______
_____15/47______
*/
