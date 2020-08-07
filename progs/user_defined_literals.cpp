#include <iostream>
using namespace std;

struct Breuk {
    int boven;
    int onder;
};

// define user-defined operator for Breuk

constexpr Breuk operator""_b(unsigned long long int i) {
    return {static_cast<int>(i), 1};
}

constexpr Breuk operator/(int links, Breuk rechts) {
    return {links * rechts.onder, rechts.boven};
}

int main() {
    Breuk b {1, 6};
    cout << b.boven << "/" << b.onder << '\n';
    b = 1/6_b;
    cout << b.boven << "/" << b.onder << '\n';
    b = 2/6_b;
    cout << b.boven << "/" << b.onder << '\n';
}