#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <initializer_list>
#include <array>
#include <algorithm>

template <typename Object, std::size_t NumRows, std::size_t NumCols>
class matrix {
private:
    using ArrayType = std::array<Object, NumRows * NumCols>;
    ArrayType a;
public:
    matrix() = default;
    matrix(const initializer_list<Object>& init) {
        if (init.size() > a.size()) throw std::out_of_range("To much elements in initializer list for class matrix.");
        std::copy(init.begin(), init.end(), a.begin());
    }
    matrix(const ArrayType& init) {
        std::copy(init.begin(), init.end(), a.begin());
    }

    using const_iterator = typename ArrayType::const_iterator;
    using iterator = typename ArrayType::iterator;
    using size_type = typename ArrayType::size_type;

    const Object& operator()(size_type row, size_type column) const {
        return a[row * NumCols + column];
    }
    Object& operator()(size_type row, size_type column) {
        return a[row * NumCols + column];
    }
    const Object& at(size_type row, size_type column) const {
        return a.at(row * NumCols + column);
    }
    Object& at(size_type row, size_type column) {
        return a.at(row * NumCols + column);
    }

    size_type numRows() const {
        return NumRows;
    }
    size_type numCols() const {
        return NumCols;
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
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::rowbegin.");
        return a.begin() + r * NumCols;
    }
    iterator rowend(size_t r) {
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::rowend.");
        return a.begin() + (r + 1) * NumCols;
    }
    const_iterator rowbegin(size_t r) const {
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::rowbegin.");
        return a.cbegin() + r * NumCols;
    }
    const_iterator rowend(size_t r) const {
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::rowend.");
        return a.cbegin() + (r + 1) * NumCols;
    }
    const_iterator crowbegin(size_t r) const {
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::crowbegin.");
        return a.cbegin() + r * NumCols;
    }
    const_iterator crowend(size_t r) const {
        if (r >= NumRows) throw std::out_of_range("Row number to high for matrix::crowend.");
        return a.cbegin() + (r + 1) * NumCols;
    }
    
    class column_iterator: public std::iterator<forward_iterator_tag, Object> {
    public:
        column_iterator(iterator i): i(i) {
        }
        const Object& operator*() const {
            return *i;
        }
        Object& operator*() {
            return *i;
        }
        column_iterator operator++(int) {
            iterator here = i;
            i += NumCols;
            return here;
        }
        column_iterator& operator++() {
            i += NumCols;
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
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::columnbegin.");
        return column_iterator(begin() + c);
    }
    column_iterator columnend(size_t c) {
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::columnend.");
        return column_iterator(begin() + c + NumRows * NumCols);
    }

    class const_column_iterator: public std::iterator<forward_iterator_tag, Object> {
    public:
        const_column_iterator(const_iterator i): i(i) {
        }
        const Object& operator*() const {
            return *i;
        }
        const_column_iterator operator++(int) {
            iterator here = i;
            i += NumCols;
            return here;
        }
        const_column_iterator& operator++() {
            i += NumCols;
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
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::columnbegin.");
        return const_column_iterator(begin() + c);
    }
    const_column_iterator columnend(size_t c) const {
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::columnend.");
        return const_column_iterator(begin() + c + NumRows * NumCols);
    }
    const_column_iterator ccolumnbegin(size_t c) const {
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::ccolumnbegin.");
        return const_column_iterator(begin() + c);
    }
    const_column_iterator ccolumnend(size_t c) const {
        if (c >= NumCols) throw std::out_of_range("Column number to high for matrix::ccolumnend.");
        return const_column_iterator(begin() + c + NumRows * NumCols);
    }

};

#endif
