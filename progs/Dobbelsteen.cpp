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

int main() {
    // rol de dobbeldsteen twintig keer
    Dobbelsteen d;
    for (int i {0}; i < 19; ++i) {
        print("{}, ", d.rol());
    }
    println("{}", d.rol());

    // bepaal verdeling
    vector<int> verdeling (6);
    for (int i {0}; i < 30'000'000; ++i) {
        ++verdeling[d.rol() - 1];
    }
    // print verdeling
    for (int i {0}; i < 6; ++i) {
        println("{}: {}", i + 1, verdeling[i]);
    }
}