#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <initializer_list>
#include <array>
#include <algorithm>

template <typename Object, std::size_t Num_rows, std::size_t Num_cols>
class matrix {
private:
    using Array_type = std::array<Object, Num_rows * Num_cols>;
    Array_type a;
public:
    matrix() = default;
    matrix(const initializer_list<Object>& init) {
        if (init.size() > a.size()) throw std::out_of_range("To much elements in initializer list for class matrix.");
        std::copy(init.begin(), init.end(), a.begin());
    }
    matrix(const Array_type& init) {
        std::copy(init.begin(), init.end(), a.begin());
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
    
    iterator rowbegin(size_t r) {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::rowbegin.");
        return a.begin() + r * Num_cols;
    }
    iterator rowend(size_t r) {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::rowend.");
        return a.begin() + (r + 1) * Num_cols;
    }
    const_iterator rowbegin(size_t r) const {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::rowbegin.");
        return a.cbegin() + r * Num_cols;
    }
    const_iterator rowend(size_t r) const {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::rowend.");
        return a.cbegin() + (r + 1) * Num_cols;
    }
    const_iterator crowbegin(size_t r) const {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::crowbegin.");
        return a.cbegin() + r * Num_cols;
    }
    const_iterator crowend(size_t r) const {
        if (r >= Num_rows) throw std::out_of_range("Row number to high for matrix::crowend.");
        return a.cbegin() + (r + 1) * Num_cols;
    }
    
    class column_iterator: public std::iterator<forward_iterator_tag, Object> {
    public:
        column_iterator(iterator i): i{i} {
        }
        const Object& operator*() const {
            return *i;
        }
        Object& operator*() {
            return *i;
        }
        column_iterator operator++(int) {
            iterator here{i};
            i += Num_cols;
            return here;
        }
        column_iterator& operator++() {
            i += Num_cols;
            return *this;
        }
        bool operator==(const column_iterator& right) {
            return i == right.i;
        }
        bool operator!=(const column_iterator& right) {
            return i != right.i;
        }
    private:
        iterator i;
    };
    
    column_iterator columnbegin(size_t c) {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::columnbegin.");
        return column_iterator(begin() + c);
    }
    column_iterator columnend(size_t c) {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::columnend.");
        return column_iterator(begin() + c + Num_rows * Num_cols);
    }

    class const_column_iterator: public std::iterator<forward_iterator_tag, Object> {
    public:
        const_column_iterator(const_iterator i): i{i} {
        }
        const Object& operator*() const {
            return *i;
        }
        const_column_iterator operator++(int) {
            iterator here{i};
            i += Num_cols;
            return here;
        }
        const_column_iterator& operator++() {
            i += Num_cols;
            return *this;
        }
        bool operator==(const const_column_iterator& right) {
            return i == right.i;
        }
        bool operator!=(const const_column_iterator& right) {
            return i != right.i;
        }
    private:
        const_iterator i;
    };

    const_column_iterator columnbegin(size_t c) const {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::columnbegin.");
        return const_column_iterator(begin() + c);
    }
    const_column_iterator columnend(size_t c) const {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::columnend.");
        return const_column_iterator(begin() + c + Num_rows * Num_cols);
    }
    const_column_iterator ccolumnbegin(size_t c) const {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::ccolumnbegin.");
        return const_column_iterator(begin() + c);
    }
    const_column_iterator ccolumnend(size_t c) const {
        if (c >= Num_cols) throw std::out_of_range("Column number to high for matrix::ccolumnend.");
        return const_column_iterator(begin() + c + Num_rows * Num_cols);
    }

};

#endif
