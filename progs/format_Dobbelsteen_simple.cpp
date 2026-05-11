import std;
using namespace std;

class Dobbelsteen {
public:
    Dobbelsteen(): dist{1, 6} {
        eng.seed(chrono::system_clock::now().time_since_epoch().count());
    }
    int rol() {
        return dist(eng);
    }
private:
    uniform_int_distribution<> dist;
    default_random_engine eng;
};

template<>
struct std::formatter<Dobbelsteen> {
    constexpr auto parse(auto& context) {
        auto iter {context.begin()};
        if (iter!= context.end() && *iter != '}') {
            throw format_error {"Ongeldige format specifier voor Dobbelsteen."};
        }
        return iter;
    }
    auto format(Dobbelsteen& d, auto& context) const {
        return format_to(context.out(), "{}", d.rol());
    }
};

int main() {
    Dobbelsteen d;
    for (int i {0}; i < 9; ++i) {
        print("{}, ", d);
    }
    println("{}", d);
    // println("{:>20}", d);
    // error: call to consteval function 'std::basic_format_string<char, Dobbelsteen&>("{:>20}")' is not a constant expression
    // error: expression '<throw-expression>' is not a constant expression
    //        throw format_error {"Ongeldige format specifier voor Dobbelsteen."};
}