// Template class Array
// Support for range-based for and ranges
// Support for initializer list
// Support for automatic template parameter deduction

import std;
#include <cassert>
using namespace std;

template <regular T> class Array {
public:
    using size_type = size_t;
    using value_type = int;
    explicit Array(size_type s);
// Support for initializer list
    Array(initializer_list<T> list);
// Construct from pair of iterators
    template<input_iterator Iter> Array(Iter begin, Iter end);
    Array(const Array<T>& v);
    Array<T>& operator=(const Array<T>& r);
    ~Array();
    T& operator[](size_type index);
    const T& operator[](size_type index) const;
    size_type length() const;
    bool operator==(const Array<T>& r) const;
    bool operator!=(const Array<T>& r) const;
// Support for range-based for and ranges
    T* begin();
    const T* begin() const;
    const T* cbegin() const;
    T* end();
    const T* end() const;
    const T* cend() const;
private:
    size_type size;
    T* data;
};

// Support for automatic template parameter deduction from iterators
template<input_iterator Iter> Array(Iter, Iter) -> Array<iter_value_t<Iter>>;

template <regular T> Array<T>::Array(size_type s): size{s}, data{new T[s]} {
}

template <regular T> Array<T>::Array(initializer_list<T> list): size{list.size()}, data{new T[size]} {
    auto list_iter{list.begin()};
    for (size_type i {0}; i < size; ++i) {
        data[i] = *list_iter++;
    }
}

template <regular T>
template<input_iterator Iter> Array<T>::Array(Iter begin, Iter end): size{static_cast<size_type>(distance(begin, end))}, data{new T[size]} {
    auto list_iter{begin};
    for (size_type i {0}; i < size; ++i) {
        data[i] = *list_iter++;
    }
}    

template <regular T> Array<T>::Array(const Array<T>& r): size{r.size}, data{new T[r.size]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = r.data[i];
}

template <regular T> Array<T>& Array<T>::operator=(const Array<T>& r) {
    Array t{r};
    swap(data, t.data);
    swap(size, t.size);
    return *this;
}

template <regular T> Array<T>::~Array() {
    delete[] data;
}

template <regular T> T& Array<T>::operator[](size_type index) {
    assert(index < size);
    return data[index];
}

template <regular T> const T& Array<T>::operator[](size_type index) const {
    assert(index < size);
    return data[index];
}

template <regular T> Array<T>::size_type Array<T>::length() const {
    return size;
}

template <regular T> bool Array<T>::operator==(const Array<T>& r) const {
    if (size != r.size)
        return false;
    for (size_type i {0}; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
}

template <regular T> bool Array<T>::operator!=(const Array<T>& r) const {
    return !(*this == r);
}

template <regular T> T* Array<T>::begin() {
    return data;
}

template <regular T> const T* Array<T>::begin() const {
    return data;
}

template <regular T> const T* Array<T>::cbegin() const {
    return data;
}

template <regular T> T* Array<T>::end() {
    return data + size;
}

template <regular T> const T* Array<T>::end() const {
    return data + size;
}

template <regular T> const T* Array<T>::cend() const {
    return data + size;
}

template <regular T> ostream& operator<<(ostream& out, const Array<T>& v) {
    for (typename Array<T>::size_type i {0}; i < v.size; ++i) {
        out << v.data[i];
        if (i != v.size-1)
            out << ',';
    }
    return out;
}

int main() {
    Array v {4, 2, 3, 1};
    println("v = {}", v);
    ranges::sort(v);
    println("na sorteren: v = {}", v);
    Array w (v.cbegin() + 1, v.cend() - 1);
    println("w = {}", w);
}
