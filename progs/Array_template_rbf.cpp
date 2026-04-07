// Template class Array
// Support for range-based for and ranges
// Support for initializer list
// Support for formatted output

import std;
using namespace std;

template <typename T> class Array {
public:
    using size_type = size_t;
    explicit Array(size_type s);
// Support for initializer list
    explicit Array(initializer_list<T> list);
    Array(const Array<T>& v);
    Array<T>& operator=(const Array<T>& r);
    ~Array();
    T& operator[](size_type index);
    const T& operator[](size_type index) const;
    size_type length() const;
    bool operator==(const Array<T>& r) const;
// Support for range-based for and ranges
    T* begin();
    const T* begin() const;
    const T* cbegin() const;
    T* end();
    const T* end() const;
    const T* cend() const;
private:
    void check_index(size_type index) const;
    size_type size;
    T* data;
};

template <typename T> Array<T>::Array(size_type s): size{s}, data{new T[s]} {
    for (size_type i {0}; i < size; ++i)
        data[i] = T{};
}

template <typename T> Array<T>::Array(initializer_list<T> list): size{list.size()}, data{new T[size]} {
    auto list_iter{list.begin()};
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
    for (size_type i {0}; i < size; ++i)
        if (data[i] != r.data[i])
            return false;
    return true;
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

int main() {
    Array v {14, 12, 13, 11};
    println("v = {}", v);
    ranges::sort(v);
    println("na sorteren: v = {}", v);
    Array r {11, 12, 13, 14};
    if (v != r)
        println("Sorteren is niet gelukt!");
    println("v (hexadecimal) = {::#X}", v);
    Array<double> w(10);
    int i {1};
    for (auto& e: w) {
        e = 1.0/i++;
    }
    println("w = {::.3f}", w);
}
