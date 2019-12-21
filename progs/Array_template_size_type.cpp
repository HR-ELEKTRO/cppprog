// Template class Array

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

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
    bool operator!=(const Array<T>& r) const;
private:
    size_type size;
    T* data;
};

template <typename T> Array<T>::Array(size_type s): size{s}, data{new T[s]} {
}

template <typename T> Array<T>::Array(const Array<T>& r): size{r.size}, data{new T[r.size]} {
    for (size_type i = 0; i < size; ++i)
        data[i] = r.data[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& r) {
    Array t{r};
    std::swap(data, t.data);
    std::swap(size, t.size);
    return *this;
}

template <typename T> Array<T>::~Array() {
    delete[] data;
}

template <typename T> T& Array<T>::operator[](size_type index) {
    assert(index < size);
    return data[index];
}

template <typename T> const T& Array<T>::operator[](size_type index) const {
    assert(index < size);
    return data[index];
}

template <typename T> typename Array<T>::size_type Array<T>::length() const {
    return size;
}

template <typename T> bool Array<T>::operator==(const Array<T>& r) const {
    if (size != r.size)
        return false;
    for (size_type i = 0; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

template <typename T> bool Array<T>::operator!=(const Array<T>& r) const {
    return !(*this == r);
}

template <typename T> ostream& operator<<(ostream& o, const Array<T>& v) {
    for (typename Array<T>::size_type i = 0; i < v.size; ++i) {
        o << v.data[i];
        if (i != v.size-1)
            o << ',';
    }
    return o;
}

int main() {
    cout << "Hoeveel elementen moet de Array bevatten? ";
    Array<double>::size_type i; cin >> i;
    if (i > 0) {
        Array<double> v{i};
        for (Array<double>::size_type j = 0; j < v.length(); ++j)
            v[j] = sqrt(double(j)); // Vul v met wortels
        cout << "v[12] = " << v[12] << endl;
        Array<int> w{i};
        for (Array<int>::size_type t = 0; t < w.length(); ++t)
            w[t] = t * t;           // Vul w met kwadraten
        cout << "w[12] = " << w[12] << endl;
    }
    else
        cout << "Dat kan niet!" << endl;
    // ...
    // Array<int> v{10};
    // for (auto e: v) {
    // error: 'begin' was not declared in this scope
    //     cout << e << ' ';
    // }
    // Array<int> w{1, 2, 3};
    // error: no matching function for call to 'Array<int>::Array(<brace-enclosed initializer list>)'
}
