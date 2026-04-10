import std;
#include <cassert>
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
    for (int i {0}; i < 20; ++i)
        print("{}, ", d);
    println("{}", d);
    
    // bepaal verdeling
    vector<int> verdeling (6);
    for (int i {0}; i < 10'000'000; ++i)
        ++verdeling[d.rol() - 1];
    for (int i {0}; i < 6; ++i) 
        println("{}: {}", i + 1, verdeling[i]);
}