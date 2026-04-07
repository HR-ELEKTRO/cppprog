// Deze class kan uitgebreid worden met een move construtor en een move assignment operator, zie Dozijn_move.cpp.
import std;
#include <cassert>
using namespace std;

class Dozijn {
public:
    Dozijn();
    Dozijn(const Dozijn& r);
    Dozijn& operator=(const Dozijn& r);
    ~Dozijn();
    int& operator[](int index);
    const int& operator[](int index) const;
    int* begin();
    const int* begin() const;
    const int* cbegin() const;
    int* end();
    const int* end() const;
    const int* cend() const;
private:
    int* data;
};

Dozijn::Dozijn(): data{new int[12]} {
    println("Constructor aangeroepen");
}

Dozijn::Dozijn(const Dozijn& r): data{new int[12]} {
    println("Copy constructor aangeroepen");
    ranges::copy(r, begin());
}

Dozijn& Dozijn::operator=(const Dozijn& r) {
    println("Copy assignment operator aangeroepen");
    ranges::copy(r, begin());
    return *this;
}

Dozijn::~Dozijn() {
    println("Destructor aangeroepen");
    delete[] data;
}

int& Dozijn::operator[](int index) {
    assert(index >= 0 && index < 12);
    return data[index];
}

const int& Dozijn::operator[](int index) const {
    assert(index >= 0 && index < 12);
    return data[index];
}

int* Dozijn::begin() {
    return data;
}

const int* Dozijn::begin() const {
    return data;
}

const int* Dozijn::cbegin() const {
    return data;
}

int* Dozijn::end() {
    return data + 12;
}

const int* Dozijn::end() const {
    return data + 12;
}

const int* Dozijn::cend() const {
    return data + 12;
}

Dozijn operator+(const Dozijn& links, const Dozijn& rechts) {
    Dozijn res;
    ranges::transform(links, rechts, res.begin(), [](int l, int r) { return l + r; });
    return res;
}

int main() {
    Dozijn a;
    // vul a met kwadraten
    int n {0};
    ranges::generate(a, [&n] () { auto r {n * n}; ++n; return r; });
    println("a = {}", a);
    Dozijn b {a};
    println("b = {}", b);

    Dozijn c {a + b};
    println("c = {}", c);

    a = b + c;
    println("a = {}", a);
}
