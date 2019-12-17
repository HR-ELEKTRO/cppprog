#include <iostream>

using namespace std;

struct Breuk {
    int boven;
    int onder;
};

int ggd(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != n)
        if (n > m) n -= m;
        else m -= n;
    return n;
}

Breuk normaliseer(Breuk b) {
    int d;
    if (b.onder < 0) {
        b.onder = -b.onder;
        b.boven = -b.boven;
    }
    d = ggd(b.boven, b.onder);
    b.boven /= d;
    b.onder /= d;
    return b;
}

Breuk maakBreuk(int t, int n) {
    return normaliseer({t, n});
}

int main() {
    auto [teller, noemer] = maakBreuk(2, -4);
    cout << "teller = " << teller << " noemer = " << noemer << '\n';
}
