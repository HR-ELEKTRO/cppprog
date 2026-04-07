// Voorbeeld van het gebruik van een rvalue reference
import std;
#include <cassert>
using namespace std;

class Dozijn {
public:
    Dozijn();
    Dozijn(const Dozijn& r);
    Dozijn(Dozijn&& r); // move constructor
    Dozijn& operator=(const Dozijn& r);
    Dozijn& operator=(Dozijn&& r); // move assignment
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

Dozijn::Dozijn(Dozijn&& r): data(r.data) {
    println("Move constructor aangeroepen");
    r.data = nullptr;
}

Dozijn& Dozijn::operator=(const Dozijn& r) {
    println("Copy assignment operator aangeroepen");
    ranges::copy(r, begin());
    return *this;
}

Dozijn& Dozijn::operator=(Dozijn&& r) {
    println("Move assignment operator aangeroepen");
    swap(data, r.data);
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

    b = move(c); // alleen als je zeker weet c niet meer nodig te hebben
    println("b = {}", b);

    Dozijn d{move(a)}; // alleen als je zeker weet a niet meer nodig te hebben
    println("d = {}", d);
}
