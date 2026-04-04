export module hr.brojz.Matrix;

import std;
using namespace std;

export template <typename Object, size_t Num_rows, size_t Num_cols>
class matrix {
private:
    using Array_type = array<Object, Num_rows * Num_cols>;
    Array_type a;
public:
    matrix() = default;
    matrix(const initializer_list<Object>& init) {
        if (init.size() > a.size()) throw out_of_range {"To much elements in initializer list for class matrix."};
        copy(init.begin(), init.end(), a.begin());
    }
    matrix(const Array_type& init) {
        copy(init.begin(), init.end(), a.begin());
    }
    using const_iterator = typename Array_type::const_iterator;
    using iterator = typename Array_type::iterator;
    using size_type = typename Array_type::size_type;
    const Object& operator()(size_type row, size_type column) const {
        return a[row * Num_cols + column];
    }
    Object& operator()(size_type row, size_type column) {
        return a[row * Num_cols + column];
    }
    const Object& at(size_type row, size_type column) const {
        return a.at(row * Num_cols + column);
    }
    Object& at(size_type row, size_type column) {
        return a.at(row * Num_cols + column);
    }
    size_type num_rows() const {
        return Num_rows;
    }
    size_type num_cols() const {
        return Num_cols;
    }
    iterator begin() {
        return a.begin();
    }
    const_iterator begin() const {
        return a.cbegin();
    }
    const_iterator cbegin() const {
        return a.cbegin();
    }
    iterator end(){
        return a.end();
    }
    const_iterator end() const {
        return a.cend();
    }
    const_iterator cend() const {
        return a.cend();
    }
};
