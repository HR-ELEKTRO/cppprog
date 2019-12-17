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
friend ostream& operator << (ostream& o, const Dozijn& a);
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

ostream& operator << (ostream& o, const Dozijn& a) {
    for (int i {0}; i < 12; ++i) {
        o << a.data[i];
        if (i != 11)
            o << ',';
    }
    return o;
}

Dozijn operator+(const Dozijn& left, const Dozijn& right) {
	Dozijn result;
	for (int i{0}; i != 12; ++i) {
		result[i] = left[i] + right[i];
	}
	return result;
}

int main() {
	Dozijn a;
	for (int j{0}; j < 12; ++j)
		a[j] = j * j; // vul a met kwadraten
	cout << "a = " << a << '\n';
	Dozijn b{a};
	cout << "b = " << b << '\n';

	Dozijn c{a + b};
	cout << "c = " << c << '\n';

	a = b + c;
	cout << "a = " << a << '\n';

	b = move(c); // alleen als je zeker weet c niet meer nodig te hebben
	cout << "b = " << b << '\n';

	Dozijn d{move(a)}; // alleen als je zeker weet a niet meer nodig te hebben
	cout << "d = " << d << '\n';
}
