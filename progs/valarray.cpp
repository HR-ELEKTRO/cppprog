#include <iostream>
#include <valarray>
using namespace std;

template<typename T>
void print_valarray(const valarray<T> v) {
    for (const auto& e: v) 
        cout << e << ' ';
    cout << '\n';
}

struct Breuk {
    Breuk(int b, int o): boven{b}, onder{o} {
    }
    Breuk(int b): boven{b}, onder{1} {
    }
    int boven;
    int onder;
};

Breuk operator+(Breuk links, Breuk rechts) {
    return Breuk{links.boven * rechts.onder + rechts.boven * links.onder, links.onder * rechts.onder};
}

//Breuk operator*(int links, Breuk rechts) {
//    return Breuk{links * rechts.boven, rechts.onder};
//}

Breuk operator*(Breuk links, Breuk rechts) {
    return Breuk{links.boven * rechts.boven, links.onder * rechts.onder};
}

ostream& operator<<(ostream& o, Breuk b) {
    return o<<b.boven<<'/'<<b.onder;
}

int main() {
    valarray<int> v1{0, 1, 2, 3, 4};
    print_valarray(v1);
    valarray<int> v2{5, 6, 7, 8, 9};
    print_valarray(v2);
    valarray<int> v3{2*v1 + v2};
    print_valarray(v3);
    
    valarray<Breuk> b1{{1, 2}, {1, 3}};
    print_valarray(b1);
    valarray<Breuk> b2{{2, 2}, {2, 3}};
    print_valarray(b2);
    valarray<Breuk> b3{2*b1 + b2};
    print_valarray(b3);
    
}
