import std;
#include <cassert>
using namespace std;

template<typename T>
int number_of_zero_bits(T n) {
    using unsigned_T = make_unsigned_t<T>;
    unsigned_T unsigned_n {static_cast<unsigned_T>(n)};
    int count {0};
    unsigned_T mask {1};
    for (size_t bit {0}; bit < sizeof(T) * 8; ++bit) {
        if ((unsigned_n & mask) == 0) {
            ++count;
        }
        mask <<= 1;
    }
    return count;
}

int number_of_zero_bits(uint8_t n) {
    static const int lookup[256] = {
        8, 7, 7, 6, 7, 6, 6, 5, 7, 6, 6, 5, 6, 5, 5, 4, 
        7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3, 
        7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
        7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
        6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
        5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
        5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
        4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0
    };
    return lookup[n];
}

int main() {
    uint8_t n1 {42};
    println("number_of_zero_bits({:0{}b}) = {}", n1, sizeof n1 * 8, number_of_zero_bits(n1));
    unsigned int n2 {42};
    println("number_of_zero_bits({:0{}b}) = {}", n2, sizeof n2 * 8, number_of_zero_bits(n2));
}
