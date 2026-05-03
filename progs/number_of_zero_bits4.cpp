import std;
#include <cassert>
using namespace std;

template<typename T>
int number_of_zero_bits(T n) requires integral<T> {
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

int main() {
    auto n {numeric_limits<int8_t>::max()};
    println("Het int8_t getal {} heeft {} bit(s) met de waarde 0.", n, number_of_zero_bits(n));
    auto m {numeric_limits<uint64_t>::min()};
    println("Het uint64_t getal {} heeft {} bit(s) met de waarde 0.", m, number_of_zero_bits(m));

    int n1 {1};
    assert(number_of_zero_bits(n1) == sizeof(int) * 8 - 1);
    int n2 {-1};
    assert(number_of_zero_bits(n2) == 0);
    int n3 {0};
    assert(number_of_zero_bits(n3) == sizeof(int) * 8);
    int n4 {numeric_limits<int>::max()};
    assert(number_of_zero_bits(n4) == 1);
    int n5 {numeric_limits<int>::min()};
    assert(number_of_zero_bits(n5) == sizeof(int) * 8 - 1);

    unsigned int n6 {numeric_limits<unsigned int>::max()};
    assert(number_of_zero_bits(n6) == 0);
    unsigned int n7 {numeric_limits<unsigned int>::min()};
    assert(number_of_zero_bits(n7) == sizeof(unsigned int) * 8);

    int8_t n8 {numeric_limits<int8_t>::min()};
    assert(number_of_zero_bits(n8) == 7);
    int8_t n9 {numeric_limits<int8_t>::max()};
    assert(number_of_zero_bits(n9) == 1);

    uint8_t n10 {numeric_limits<uint8_t>::min()};
    assert(number_of_zero_bits(n10) == 8);
    uint8_t n11 {numeric_limits<uint8_t>::max()};
    assert(number_of_zero_bits(n11) == 0);

    uint64_t n12 {numeric_limits<uint64_t>::min()};
    assert(number_of_zero_bits(n12) == sizeof(uint64_t) * 8);
    uint64_t n13 {numeric_limits<uint64_t>::max()};
    assert(number_of_zero_bits(n13) == 0);

    char n14 {'A'};
    println("'{}' = {:0b}", n14, static_cast<int>(n14));
    assert(number_of_zero_bits(n14) == 6);
    println("number_of_zero_bits('{}') = {}", n14, number_of_zero_bits(n14));

    // double n15 {3.14};
    // println("number_of_zero_bits({}) = {}", n15, number_of_zero_bits(n15));
    // error: no matching function for call to 'number_of_zero_bits(double&)'
    // note: constraints not satisfied
}
