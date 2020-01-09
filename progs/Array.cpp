// Een zelfgemaakt alternatief voor int[]

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Array {
public:
    explicit Array(int s);
    Array(const Array& r);
    Array& operator=(const Array& r);
    ~Array();
    int& operator[](int index);
    const int& operator[](int index) const;
    int length() const;
    bool operator==(const Array& r) const;
    bool operator!=(const Array& r) const;
private:
    int size;
    int* data;

friend ostream& operator<<(ostream& o, const Array& a);
};

Array::Array(int s): size{s}, data{new int[s]} {
}

Array::Array(const Array& r): size{r.size}, data{new int[r.size]} {
{0}    for (int i {0}; i < size; ++i)
        data[i] = r.data[i];
}

Array& Array::operator=(const Array& r) {
    Array t{r};
    std::swap(data, t.data);
    std::swap(size, t.size);
    return *this;
}

Array::~Array() {
    delete[] data;
}

int& Array::operator[](int index) {
    assert(index >= 0 && index < size);
    return data[index];
}

const int& Array::operator[](int index) const {
    assert(index >= 0 && index < size);
    return data[index];
}

int Array::length() const {
    return size;
}

bool Array::operator==(const Array& r) const {
    if (size != r.size)
        return false;
    for (int i {0}; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

bool Array::operator!=(const Array& r) const {
    return !(*this == r);
}

ostream& operator<<(ostream& o, const Array& a) {
    for (int i {0}; i < a.size; ++i) {
        o << a.data[i];
        if (i != a.size - 1)
            o << ',';
    }
    return o;
}

int main() {
    cout << "Hoeveel elementen moet de Array bevatten? ";
    int i; 
    cin >> i;
    if (i > 0) {
        Array a{i};
        cout << "a = " << a << '\n';
        for (int j {0}; j < a.length(); ++j)
            a[j] = j * j; // vul a met kwadraten
        cout << "a = " << a << '\n';
        Array b{a};
        cout << "b = " << b << '\n';
        cout << "a[12] = " << a[12] << '\n';
        cout << "b[12] = " << b[12] << '\n';
        a[0] = 4; 
        cout << "a[0] = " << a[0] << '\n';
        cout << "a = " << a << '\n';
        cout << "b = " << b << '\n';

        if (a == b)
            cout << "a is nu gelijk aan b.\n";
        else 
            cout << "a is nu ongelijk aan b.\n";

        b = a;
        cout << "b = a is uitgevoerd.\n";
        cout << "a = " << a << '\n';
        cout << "b = " << b << '\n';

        if (a != b) 
            cout << "a is nu ongelijk aan b.\n";
        else 
            cout << "a is nu gelijk aan b.\n";
    }
    else
        cout << "Doe niet zo negatief!\n";
}
