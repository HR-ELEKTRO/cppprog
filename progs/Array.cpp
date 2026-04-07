// Een zelfgemaakt alternatief voor int[]

import std;
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
private:
    size_type size;
    int* data;
friend bool operator==(const Array& l, const Array& r);
friend ostream& operator<<(ostream& out, const Array& r);
};

Array::Array(size_type s): size{s}, data{new int[s]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = 0;
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

bool operator==(const Array& l, const Array& r) {
    if (l.size != r.size)
        return false;
    for (Array::size_type i {0}; i < l.size; ++i)
        if (l.data[i] != r.data[i])
            return false;
    return true;
}

ostream& operator<<(ostream& out, const Array& r) {
    for (Array::size_type i {0}; i < r.size; ++i) {
        out << r.data[i];
        if (i != r.size - 1)
            out << ", ";
    }
    return out;
}

template<>
struct std::formatter<Array>: public formatter<string> {
    auto format(const Array& a, auto& context) const {
        ostringstream ss;
        ss << a;
        return formatter<string>::format(ss.str(), context);
    }
};

int main() {
    print("Hoeveel elementen moet de Array bevatten? ");
    Array::size_type i; 
    cin >> i;
    Array a {i};
    println("a = {}", a);
    for (Array::size_type j {0}; j < a.length(); ++j)
        a[j] = j * j; // vul a met kwadraten
    println("a = {}", a);
    Array b {a};
    println("b = {}", b);
    println("a[12] = {}", a[12]);
    println("b[12] = {}", b[12]);
    a[0] = 4;
    println("a[0] = {}", a[0]);
    println("a = {}", a);
    println("b = {}", b);

    if (a == b)
        println("a is nu gelijk aan b.");
    else 
        println("a is nu ongelijk aan b.");

    b = a;
    println("b = a is uitgevoerd.");
    println("a = {}", a);
    println("b = {}", b);

    if (a != b) 
        println("a is nu ongelijk aan b.");
    else 
        println("a is nu gelijk aan b.");
}
