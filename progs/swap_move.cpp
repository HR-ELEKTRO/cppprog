// Voorbeeld van het gebruik van een rvalue reference
#include <iostream>
#include <utility>
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
private:
    int* data;
friend ostream& operator<<(ostream& o, const Dozijn& a);
};

Dozijn::Dozijn(): data{new int[12]} {
    cout << "Constructor aangeroepen\n";
}

Dozijn::Dozijn(const Dozijn& r): data{new int[12]} {
    cout << "Copy constructor aangeroepen\n";
    for (int i {0}; i < 12; ++i) {
        data[i] = r.data[i];
    }
}

Dozijn::Dozijn(Dozijn&& r): data(r.data) {
    cout << "Move constructor aangeroepen\n";
    r.data = nullptr;
}

Dozijn& Dozijn::operator=(const Dozijn& r) {
    cout << "Copy assignment operator aangeroepen\n";
    for (int i {0}; i < 12; ++i) {
        data[i] = r.data[i];
    }
    return *this;
}

Dozijn& Dozijn::operator=(Dozijn&& r) {
    cout << "Move assignment operator aangeroepen\n";
    swap(data, r.data);
    return *this;
}

Dozijn::~Dozijn() {
    cout << "Destructor aangeroepen\n";
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

ostream& operator<<(ostream& o, const Dozijn& a) {
    for (int i {0}; i < 12; ++i) {
        o << a.data[i];
        if (i != 11)
            o << ',';
    }
    return o;
}

void swap(Dozijn& d1, Dozijn& d2) {
    Dozijn hulp{d1};
    d1 = d2;
    d2 = hulp;
}

void swap_move(Dozijn& d1, Dozijn& d2) {
    Dozijn hulp{move(d1)};
    d1 = move(d2);
    d2 = move(hulp);
}

int main() {
    Dozijn a, b;
    for (int j {0}; j < 12; ++j) {
        a[j] = j + j; // vul a met dubbelen
        b[j] = j * j; // vul b met kwadraten
    }
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    swap(a, b);

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    swap_move(a, b);

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';

    std::swap(a, b);

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
}
