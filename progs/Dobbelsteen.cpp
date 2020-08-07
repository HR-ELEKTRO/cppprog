#include <iostream>
#include <random>
#include <vector>
#include <chrono>
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

ostream& operator<<(ostream& out, Dobbelsteen& d) {
    return out<<d.rol();
}

int main() {
    Dobbelsteen d;
    for (int i {0}; i < 20; ++i)
        cout << d << ", ";
    cout << d << '\n';
    
    // bepaal verdeling
    vector<int> verdeling (6);
    for (int i {0}; i < 10'000'000; ++i)
        ++verdeling[d.rol() - 1];
    for (int i {0}; i < 6; ++i) 
        cout << i+1 << ": " << verdeling[i] << '\n';
}