#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Save_vector: public vector<T> {
public:
    using vector<T>::vector; // use constructors from vector
    using size_type = typename vector<T>::size_type; 
    T& operator[](size_type i) {
        return vector<T>::at(i);
    }
    const T& operator[](size_type i) const {
        return vector<T>::at(i);
    }
};

int main() {
    try {
        vector<int> v1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        Save_vector<int> v2 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        cout << "v1[10] = " << v1[10] << '\n';
        cout << "v2[10] = " << v2[10] << '\n';
    } catch (const exception& e) {
        cerr << e.what() << '\n';
    }
}

// $ g++ -std=c++14 -pedantic -Wall -g3 -O0 Save_vector.cpp
/* Output:
v1[10] = 67
v2[10] = vector::_M_range_check: __n (which is 10) >= this->size() (which is 10)
*/

// $ g++ -std=c++14 -pedantic -Wall -g3 -O0 -D_GLIBCXX_DEBUG Save_vector.cpp
/* Output:
/usr/lib/gcc/x86_64-pc-msys/9.1.0/include/c++/debug/vector:427:
In function:
    std::__debug::vector<_Tp, _Allocator>::reference
    std::__debug::vector<_Tp,
    _Allocator>::operator[](std::__debug::vector<_Tp,
    _Allocator>::size_type) [with _Tp = int; _Allocator =
    std::allocator<int>; std::__debug::vector<_Tp, _Allocator>::reference =
    int&; std::__debug::vector<_Tp, _Allocator>::size_type = long unsigned
    int]

Error: attempt to subscript container with out-of-bounds index 10, but
container only holds 10 elements.

Objects involved in the operation:
    sequence "this" @ 0x0xffffcb20 {
      type = std::__debug::vector<int, std::allocator<int> >;
    }
Aborted (core dumped)
*/