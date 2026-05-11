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
        auto iter {begin(context)};
        if (*iter == 's') {
            gebruik_symbolen = true;
            context.advance_to(iter+1);
            return string_formatter.parse(context);
        }
        gebruik_symbolen = false;
        return int_formatter.parse(context);
    }
    auto format(Dobbelsteen& d, auto& context) const {
        if (gebruik_symbolen) {
            const array symbols {"⚀", "⚁", "⚂", "⚃", "⚄", "⚅"};
            return string_formatter.format(symbols[d.rol() - 1], context);
        }
        return int_formatter.format(d.rol(), context);
    }
private:
    bool gebruik_symbolen;
    formatter<int> int_formatter;
    formatter<string> string_formatter;
};

int main() {
    Dobbelsteen d;
    println("{:>3}", d);
    println("{:s>3}", d);
    println("{:>03b}", d);
    println("{:s>3?}", d);
    for (int i {0}; i < 9; ++i) {
        print("{:s}, ", d);
    }
    println("{:s}", d);

}