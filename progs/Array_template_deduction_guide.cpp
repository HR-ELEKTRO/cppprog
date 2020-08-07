// Template class Array
// Support for range-based for
// Support for initializer list
// Support for automatic template parameter deduction

#include <iostream>
#include <cmath>
#include <cassert>
#include <initializer_list>

using namespace std;

template <typename T> class Array {
public:
    using size_type = size_t;
    using value_type = int;
    explicit Array(size_type s);
// Support for initializer list
    Array(initializer_list<T> list);
// Construct from pair of iterators
    template<typename Iter> Array(Iter begin, Iter end);
    Array(const Array<T>& v);
    Array<T>& operator=(const Array<T>& r);
    ~Array();
    T& operator[](size_type index);
    const T& operator[](size_type index) const;
    size_type length() const;
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
    size_type size;
    T* data;
};

// Support for automatic template parameter deduction from iterators
template<typename Iter> Array(Iter, Iter) -> Array<typename iterator_traits<Iter>::value_type>;

template <typename T> Array<T>::Array(size_type s): size{s}, data{new T[s]} {
}

template <typename T> Array<T>::Array(initializer_list<T> list): size{list.size()}, data{new T[size]} {
    auto list_iter{list.begin()};
    for (size_type i {0}; i < size; ++i) {
        data[i] = *list_iter++;
    }
}

template <typename T>
template<typename Iter> Array<T>::Array(Iter begin, Iter end): size{static_cast<size_type>(distance(begin, end))}, data{new T[size]} {
    auto list_iter{begin};
    for (size_type i {0}; i < size; ++i) {
        data[i] = *list_iter++;
    }
}    

template <typename T> Array<T>::Array(const Array<T>& r): size{r.size}, data{new T[r.size]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = r.data[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T>& r) {
    Array t{r};
    swap(data, t.data);
    swap(size, t.size);
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
    for (size_type i {0}; i < size; ++i)
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

template <typename T> ostream& operator<<(ostream& out, const Array<T>& v) {
    for (typename Array<T>::size_type i {0}; i < v.size; ++i) {
        out << v.data[i];
        if (i != v.size-1)
            out << ',';
    }
    return out;
}

int main() {
    Array v {1, 2, 3, 4};
    for (auto e: v) {
        cout << e << " ";
    }
    cout << '\n';
    Array w (v.cbegin() + 1, v.cend() - 1);
    for (auto e: w) {
        cout << e << " ";
    }
    cout << '\n';
}
