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
struct std::formatter<Dobbelsteen>: public formatter<int> {
    auto format(Dobbelsteen& d, auto& context) const {
        return formatter<int>::format(d.rol(), context);
    }
};

int main() {
    Dobbelsteen d;
    println("|{:<8}|", d);
    println("|{:>8}|", d);
    println("|{:^8}|", d);
    println("|{:0>8b}|", d);
}