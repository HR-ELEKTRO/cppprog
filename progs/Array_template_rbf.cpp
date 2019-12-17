// Template class Array
// Support for range-based for
// Support for initializer list

#include <iostream>
#include <cmath>
#include <cassert>
#include <initializer_list>

using namespace std;

template <typename T> class Array {
public:
    explicit Array(int s);
// Support for initializer list
    Array(initializer_list<T> list);
    Array(const Array<T>& v);
    Array<T>& operator=(const Array<T>& r);
    ~Array();
    T& operator[](int index);
    const T& operator[](int index) const;
    int length() const;
    bool operator==(const Array<T>& r) const;
    bool operator!=(const Array<T>& r) const;
// Support for range-based for
    T* begin();
    const T* begin() const;
    const T* cbegin() const;
    T* end();
    const T* end() const;
    const T* cend() const;
private:
    int size;
    T* data;
};

template <typename T> Array<T>::Array(int s): size(s), data(new T[s]) {
}

template <typename T> Array<T>::Array(initializer_list<T> list): size(list.size()), data(new T[size]) {
    auto listIter = list.begin();
    for (int i = 0; i < size; ++i) {
        data[i] = *listIter++;
    }
}

template <typename T> Array<T>::Array(const Array<T>& r): size(r.size), data(new T[r.size]) {
    for (int i = 0; i < size; ++i)
        data[i] = r.data[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& r) {
    Array t(r);
    std::swap(data, t.data);
    std::swap(size, t.size);
    return *this;
}

template <typename T> Array<T>::~Array() {
    delete[] data;
}

template <typename T> T& Array<T>::operator[](int index) {
    assert(index >= 0 && index < size);
    return data[index];
}

template <typename T> const T& Array<T>::operator[](int index) const {
    assert(index >= 0 && index < size);
    return data[index];
}

template <typename T> int Array<T>::length() const {
    return size;
}

template <typename T> bool Array<T>::operator==(const Array<T>& r) const {
    if (size != r.size)
    return false;
    for (int i = 0; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

template <typename T> bool Array<T>::operator!=(const Array<T>& r) const {
    return !(*this == r);
}

template <typename T> T* Array<T>::begin() {
    return data;
}

template <typename T> const T* Array<T>::begin() const {
    return data;
}

template <typename T> const T* Array<T>::cbegin() const {
    return data;
}

template <typename T> T* Array<T>::end() {
    return data + size;
}

template <typename T> const T* Array<T>::end() const {
    return data + size;
}

template <typename T> const T* Array<T>::cend() const {
    return data + size;
}

template <typename T> ostream& operator << (ostream& o, const Array<T>& v) {
    for (int i = 0; i < v.size; ++i) {
        o << v.data[i];
        if (i != v.size-1)
            o << ',';
    }
    return o;
}

int main() {
    Array<int> v = {1, 2, 3, 4};
    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;
    Array<double> w(10);
    int i = 1;
    for (auto& e: w) {
        e = 1.0/i++;
    }
    for (auto e: w) {
        cout << e << " ";
    }
    cin.get();
    return 0;
}
