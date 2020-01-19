// Een zelfgemaakt alternatief voor int[]

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Array {
public:
    using size_type = size_t;
    explicit Array(size_type s);
    Array(const Array& r);
    Array& operator=(const Array& r);
    ~Array();
    int& operator[](size_type index);
    const int& operator[](size_type index) const;
    size_type length() const;
    bool operator==(const Array& r) const;
    bool operator!=(const Array& r) const;
private:
    size_type size;
    int* data;
friend ostream& operator<<(ostream& o, const Array& a);
};

Array::Array(size_type s): size{s}, data{new int[s]} {
}

Array::Array(const Array& r): size{r.size}, data{new int[r.size]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = r.data[i];
}

Array& Array::operator=(const Array& r) {
    Array t {r};
    swap(data, t.data);
    swap(size, t.size);
    return *this;
}

Array::~Array() {
    delete[] data;
}

int& Array::operator[](size_type index) {
    assert(index < size);
    return data[index];
}

const int& Array::operator[](size_type index) const {
    assert(index < size);
    return data[index];
}

Array::size_type Array::length() const {
    return size;
}

bool Array::operator==(const Array& r) const {
    if (size != r.size)
        return false;
    for (size_type i {0}; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

bool Array::operator!=(const Array& r) const {
    return !(*this == r);
}

ostream& operator<<(ostream& o, const Array& a) {
    for (Array::size_type i {0}; i < a.size; ++i) {
        o << a.data[i];
        if (i != a.size - 1)
            o << ',';
    }
    return o;
}

int main() {
    cout << "Hoeveel elementen moet de Array bevatten? ";
    Array::size_type i; 
    cin >> i;
    Array a {i};
    cout << "a = " << a << '\n';
    for (Array::size_type j {0}; j < a.length(); ++j)
        a[j] = j * j; // vul a met kwadraten
    cout << "a = " << a << '\n';
    Array b {a};
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
