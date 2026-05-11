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
        return int_formatter.parse(context);
    }
    auto format(Dobbelsteen& d, auto& context) const {
        return int_formatter.format(d.rol(), context);
    }
private:
    formatter<int> int_formatter;
};

int main() {
    Dobbelsteen d;
    println("|{:<8}|", d);
    println("|{:>8}|", d);
    println("|{:^8}|", d);
    println("|{:0>8b}|", d);
}