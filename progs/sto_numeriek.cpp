import std;
using namespace std;

int main() {
    string s1 {"-123.45"};
    size_t pos;
    int i1 = stoi(s1, &pos);
    println("i1 = {}, pos = {}", i1, pos);
    // i1 = -123, pos = 4
    int i2 = stoi(s1, &pos, 16);
    println("i2 = {}, pos = {}", i2, pos);
    // i2 = -291, pos = 4
    int i3 = stoi(s1, &pos, 7);
    println("i3 = {}, pos = {}", i3, pos);
    // i3 = -66, pos = 4
    string s2 {"0123 octaal"};
    int i4 = stoi(s2, &pos, 0);
    println("i4 = {}, pos = {}", i4, pos);
    // i4 = 83, pos = 4
    string s3 {"0b123 binair"};
    int i5 = stoi(s3, &pos, 0);
    println("i5 = {}, pos = {}", i5, pos);
    // i5 = 0, pos = 1
    // Jammer, binair wordt niet ondersteund.
    string s4 {"0x123 hexadecimaal"};
    int i6 = stoi(s4, &pos, 0);
    println("i6 = {}, pos = {}", i6, pos);
    // i6 = 291, pos = 5
    try {
        string s5 {"Hallo 123"};
        int i7 = stoi(s5, &pos, 2);
        println("i7 = {}, pos = {}", i7, pos);
    }
    catch (const invalid_argument& e) {
        println("invalid_argument: {}", e.what());
    }
    catch (const out_of_range& e) {
        println("out_of_range: {}", e.what());
    }
    // invalid_argument: stoi
    try {
        string s6 {"12345678901234567890"};
        int i8 = stoi(s6, &pos, 10);
        println("i8 = {}, pos = {}", i8, pos);
    }
    catch (const invalid_argument& e) {
        println("invalid_argument: {}", e.what());
    }
    catch (const out_of_range& e) {
        println("out_of_range: {}", e.what());
    }
    // out_of_range: stoi
    double d = stod(s1, &pos);
    println("d = {}, pos = {}", d, pos);
    // d = -123.45, pos = 7
}