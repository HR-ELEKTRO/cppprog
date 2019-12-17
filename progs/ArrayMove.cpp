// Een zelfgemaakt alternatief voor int[]

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Array {
public:
    explicit Array(int s);
    Array(const Array& r);
    Array(Array&&); // move constructor
    Array& operator=(const Array& r);
    Array& operator=(Array&& r); // move assignment
    ~Array();

    int& operator[](int index);
    const int& operator[](int index) const;
    int length() const;
    bool operator==(const Array& r) const;
    bool operator!=(const Array& r) const;
private:
    int size;
    int* data;
// niet in de les behandeld:
friend ostream& operator << (ostream& o, const Array& a);
};

Array::Array(int s): size{s}, data{new int[s]} {
}

Array::Array(const Array& r): size{r.size}, data{new int[r.size]} {
    for (int i {0}; i < size; ++i)
        data[i] = r.data[i];
}

Array::Array(Array&& r): size{r.size}, data(r.data) {
	r.size = 0;
	r.data = nullptr;
}

Array& Array::operator=(const Array& r) {
    Array t{r};
    std::swap(size, t.size);
    std::swap(data, t.data);
    return *this;
}

Array& Array::operator=(Array&& r) {
    std::swap(size, r.size);
    std::swap(data, r.data);
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

ostream& operator << (ostream& o, const Array& a) {
    for (int i {0}; i < a.size; ++i) {
        o << a.data[i];
        if (i != a.size - 1)
            o << ',';
    }
    return o;
}

Array operator+(const Array& left, const Array& right) {
	assert(left.length() == right.length());
	Array result{left.length()};
	for (int i{0}; i != left.length(); ++i) {
		result[i] = left[i] + right[i];
	}
	return result;
}

int main() {
    cout << "Hoeveel elementen moet de Array bevatten? ";
    int i; 
    cin >> i;
    if (i > 0) {
        Array a{i};
        cout << "a = " << a << endl;
        for (int j{0}; j < a.length(); ++j)
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

        Array r{a.length()};
        r = a + b;
        cout << "r = " << r << '\n';

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
