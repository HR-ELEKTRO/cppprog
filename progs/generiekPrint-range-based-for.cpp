#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// generieke print m.b.v. range-based-for
// kan gebruikt worden voor ALLE containers

template<typename C> void print(const C& c) {
    cout << "De inhoud van de container is:\n";
    for (const auto& e: c) {
        cout << e << " ";
    }
    cout << '\n';
}

int main() {
    vector<int> v;
    list<double> l;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        l.push_back(1.0 / i);
    }
    print(v);
    print(l);
    string s{"Hallo"};
    print(s);
}
