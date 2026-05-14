import std;
#include <cassert>
using namespace std;

class Breuk {
public:
    Breuk(int t = 0, int n = 1);
private:
    int boven;
    int onder;
    friend struct std::formatter<Breuk>;
};

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d {gcd(boven, onder)};
    boven /= d;
    onder /= d;
}

template<>
struct std::formatter<Breuk> {
    constexpr auto parse(format_parse_context& context) {
        int number_of_parsed_colons {0};
        total_format.clear();
        teller_format.clear();
        noemer_format.clear();
        auto iter {context.begin()};
        for (; iter != context.end(); ++iter) {
            if (*iter == '}') { break; }
            if (number_of_parsed_colons == 0) {
                if (*iter == ':') {
                    ++number_of_parsed_colons;
                }
                else {
                    total_format += *iter;
                }
            }
            else if (number_of_parsed_colons == 1) {
                if (*iter == ':') {
                    ++number_of_parsed_colons;
                }
                else {
                    teller_format += *iter;
                }
            }
            else {
                noemer_format += *iter;
            }
        }
        return iter;
    }
    auto format(const Breuk& breuk, auto& context) const {
        string teller_fmt {teller_format.empty() ? "{}" : "{:" + teller_format + "}"};
        string noemer_fmt {noemer_format.empty() ? teller_fmt : "{:" + noemer_format + "}"};
        string teller_text {vformat(teller_fmt, make_format_args(breuk.boven))};
        string noemer_text {vformat(noemer_fmt, make_format_args(breuk.onder))};
        string inner_text {teller_text + "/" + noemer_text};
        string total_fmt {total_format.empty() ? "{}" : "{:" + total_format + "}"};
        string final_text {vformat(total_fmt, make_format_args(inner_text))};
        return format_to(context.out(), "{}", final_text);
    }
private:
    string total_format;
    string teller_format;
    string noemer_format;
};

int main() {
    Breuk b {30, 94};
    println("Breuk b = {}", b);
    println("Breuk b = {::#0X}", b);
    println("Breuk b = {::#0b}", b);
    // Uitlijnen werkt zoals verwacht:
    println("Breuk b = {:_^16}", b);
    println("Breuk b = {:_^16:#0X}", b);
    println("Breuk b = {:_^16:#0b:#0x}", b);
    Breuk b1 {60, 142};
    Breuk b2 {1001, 30011};
    println("Breuk b1 = {}", b1);
    println("Breuk b2 = {}", b2);
    println("Breuk b1 = {:>21}", b1);
    println("Breuk b2 = {:>21}", b2);
    println("Breuk b1 = {:>21:^10}", b1);
    println("Breuk b2 = {:>21:^10}", b2);
    println("Breuk b1 = {:>21:>6}", b1);
    println("Breuk b2 = {:>21:>6}", b2);
    println("Breuk b1 = {:>21:#0X}", b1);
    println("Breuk b1 = {:>21:#0b}", b1);
    println("Breuk b1 = {:>21:#0X:#0b}", b1);
    println("Breuk b1 = {:>21:>10:<10}", b1);
    println("Breuk b2 = {:>21:>10:<10}", b2);
}

/* Output:
Breuk b = 15/47
Breuk b = 0XF/0X2F
Breuk b = 0b1111/0b101111
Breuk b = _____15/47______
Breuk b = ____0XF/0X2F____
Breuk b = __0b1111/0x2f___
Breuk b1 = 30/71
Breuk b2 = 1001/30011
Breuk b1 =                 30/71
Breuk b2 =            1001/30011
Breuk b1 =     30    /    71
Breuk b2 =    1001   /  30011
Breuk b1 =             30/    71
Breuk b2 =           1001/ 30011
Breuk b1 =             0X1E/0X47
Breuk b1 =     0b11110/0b1000111
Breuk b1 =        0X1E/0b1000111
Breuk b1 =         30/71
Breuk b2 =       1001/30011
*/