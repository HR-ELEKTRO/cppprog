import std;
using namespace std;

enum class Stoplicht: int8_t {groen, oranje, rood};

ostream& operator<<(ostream& out, Stoplicht s) {
    using enum Stoplicht;
    switch (s) {
    case groen:
        out<<"groen";
        break;
    case oranje:
        out<<"oranje";
        break;
    case rood:
        out<<"rood";
        break;
    }
    return out;
}

template<>
struct std::formatter<Stoplicht>: public formatter<string> {
    auto format(Stoplicht s, auto& context) const {
        ostringstream ss;
        ss << s;
        return formatter<string>::format(ss.str(), context);;
    }
};

int main()
{
    using enum Stoplicht;
    println("sizeof(Stoplicht) = {}", sizeof(Stoplicht));
    Stoplicht s {rood};
    println("sizeof s = {}", sizeof s);
    cout << "s = " << s << '\n';
    println("s = {}", s);
    println("s = {:>10}", s);
    println("Underlying value for red = {}", to_underlying(rood));
}
