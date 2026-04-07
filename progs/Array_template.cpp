// Template class Array

import std;
using namespace std;

template <typename T> class Array;
template <typename T> ostream& operator<<(ostream& out, const Array<T>& r);

template <typename T> class Array {
public:
    using size_type = size_t;
    explicit Array(size_type s);
    Array(const Array<T>& v);
    Array<T>& operator=(const Array<T>& r);
    ~Array();
    T& operator[](size_type index);
    const T& operator[](size_type index) const;
    size_type length() const;
    bool operator==(const Array<T>& r) const;
private:
    void check_index(size_type index) const;
    size_type size;
    T* data;
friend ostream& operator<< <>(ostream& out, const Array<T>& r);
};

template <typename T> Array<T>::Array(size_type s): size{s}, data{new T[s]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = T{};
}

template <typename T> Array<T>::Array(const Array<T>& r): size{r.size}, data{new T[r.size]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = r.data[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& r) {
    Array t {r};
    swap(data, t.data);
    swap(size, t.size);
    return *this;
}

template <typename T> Array<T>::~Array() {
    delete[] data;
}

template <typename T> void Array<T>::check_index(size_type index) const {
    if (index >= size) {
        throw std::out_of_range("Gebruikte index (" + to_string(index) + ") ligt buiten de grenzen van de Array (0.." + to_string(size - 1) + ")");
    }
}

template <typename T> T& Array<T>::operator[](size_type index) {
    check_index(index);
    return data[index];
}

template <typename T> const T& Array<T>::operator[](size_type index) const {
    check_index(index);
    return data[index];
}

template <typename T> typename Array<T>::size_type Array<T>::length() const {
    return size;
}

template <typename T> bool Array<T>::operator==(const Array<T>& r) const {
    if (size != r.size)
        return false;
    for (typename Array<T>::size_type i {0}; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

template <typename T> ostream& operator<<(ostream& out, const Array<T>& r) {
    for (typename Array<T>::size_type i {0}; i < r.size; ++i) {
        out << r.data[i];
        if (i != r.size - 1)
            out << ", ";
    }
    return out;
}

template< typename T>
struct std::formatter<Array<T>>: public formatter<string> {
    auto format(const Array<T>& a, auto& context) const {
        ostringstream ss;
        ss << a;
        return formatter<string>::format(ss.str(), context);
    }
};

int main() {
    print("Hoeveel elementen moet de Array bevatten? ");
    Array<double>::size_type i; 
    cin >> i;
    Array<double> v {i};
    println("v = {}", v);
    for (Array<double>::size_type j {0}; j < v.length(); ++j)
        v[j] = sqrt(j); // Vul v met wortels
    println("v = {}", v);
    if (v != v)
        println("Dit kan niet waar zijn!");
    try {
        println("v[12] = {}", v[12]);
    } catch (const out_of_range& e) {
        println("Exception: {}", e.what());
    }
    Array<int> w {i};
    println("w = {}", w);
    for (Array<int>::size_type t {0}; t < w.length(); ++t)
        w[t] = t * t;   // Vul w met kwadraten
    println("w = {}", w);
    try {
        println("w[12] = {}", w[12]);
    } catch (const out_of_range& e) {
        println("Exception: {}", e.what());
    }

    // Array<int> v {10};
    // for (auto e: v) {
    // error: 'begin' was not declared in this scope; did you mean 'std::begin'?
    // error: 'end' was not declared in this scope; did you mean 'std::end'?
    //     print('"{} ", e);
    // }

    // Array<int> a {1, 2, 3};
    // error: no matching function for call to 'Array<int>::Array(<brace-enclosed initializer list>)'

    Array<thread> t {2};
    t[0] = thread {[]() { println("Thread 1 meldt zich"); }};
    t[1] = thread {[]() { println("Thread 2 meldt zich"); }};
    // Array<thread> c {2};
    // c = t;
    // error: use of deleted function 'std::thread& std::thread::operator=(const std::thread&)'
    // Array<thread> d {t};
    // error: use of deleted function 'std::thread& std::thread::operator=(const std::thread&)'
    for (size_t i {0}; i < t.length(); ++i)
        t[i].join();
}
