#include <iostream>
#include <valarray>
#include <numeric>
#include <cassert>

using namespace std;

template<typename T>
void print_valarray(const valarray<T> v) {
    for (const auto& e: v) 
        cout << e << ' ';
    cout << '\n';
}

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
    Breuk& operator+=(const Breuk& rechts);
    Breuk& operator*=(const Breuk& rechts);
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
};

const Breuk operator+(const Breuk& links, const Breuk& rechts);
const Breuk operator*(const Breuk& links, const Breuk& rechts);

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

Breuk& Breuk::operator+=(const Breuk& rechts) {
    boven = boven * rechts.onder + onder * rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator*=(const Breuk& rechts) {
    boven *= rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
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

const Breuk operator+(const Breuk& links, const Breuk& rechts) {
    Breuk copy_links {links};
    copy_links += rechts;
    return copy_links;
}

const Breuk operator*(const Breuk& links, const Breuk& rechts) {
    Breuk copy_links {links};
    copy_links *= rechts;
    return copy_links;
}

ostream& operator<<(ostream& out, const Breuk& b) {
    return out << b.boven << '/' << b.onder;
}

int main() {
    valarray<int> v1 {0, 1, 2, 3, 4};
    print_valarray(v1);
    valarray<int> v2 {5, 6, 7, 8, 9};
    print_valarray(v2);
    valarray<int> v3 {2 * v1 + v2};
    print_valarray(v3);
    
    valarray<Breuk> b1 { {1, 2}, {1, 3} };
    print_valarray(b1);
    valarray<Breuk> b2 { {2, 2}, {2, 3} };
    print_valarray(b2);
    valarray<Breuk> b3 {2 * b1 + b2};
    print_valarray(b3);
}
