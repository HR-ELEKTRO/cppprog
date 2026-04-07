// Een zelfgemaakt alternatief voor int[]

import std;
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
private:
    void check_index(size_type index) const;
    size_type size;
    int* data;
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

void Array::check_index(size_type index) const {
    if (index >= size) {
        throw std::out_of_range("Gebruikte index (" + to_string(index) + ") ligt buiten de grenzen van de Array (0.." + to_string(size - 1) + ")");
    }
}

int& Array::operator[](size_type index) {
    check_index(index);
    return data[index];
}

const int& Array::operator[](size_type index) const {
    check_index(index);
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
    try {
        println("a[12] = {}", a[12]);
        println("b[12] = {}", b[12]);
    } catch (const std::out_of_range& e) {
        println("Exception: {}", e.what());
    }
    try {
        a[0] = 4;
        println("a[0] = {}", a[0]);
    } catch (const std::out_of_range& e) {
        println("Exception: {}", e.what());
    }
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
