import std;
using namespace std;

int main() {
    byte b1 {234};
    // println("b1 = {}", b1);
    // error: static assertion failed: std::formatter must be specialized for each type being formatted
    // cout << "b1 = " << b1 << endl;
    // error: no match for 'operator<<' (operand types are 'std::basic_ostream<char>' and 'std::byte')
    println("b1 = {}", to_integer<int>(b1));
    byte b2;
    b2 = b1 >> 3;
    println("b2 = {}", to_integer<uint8_t>(b2));
    // byte b3;
    // b3 = b1 + b2;
    // error: no match for 'operator+' (operand types are 'std::byte' and 'std::byte)'
    uint8_t i1 {234};
    println("i1 = {}", i1);
    uint8_t i2;
    i2 = i1 >> 3;
    println("i2 = {}", i2);
    uint8_t i3;
    i3 = i1 + i2;
    println("i3 = {}", i3);
    println("islower(i3) = {}", islower(i3));
    char c1 {66};
    println("c1 = {}", c1);
    char c2;
    c2 = c1 >> 1;
    println("c2 = {}", c2);
    char c3;
    c3 = c1 + c2;
    println("c3 = {}", c3);
    println("islower(i3) = {}", islower(i3));
}
