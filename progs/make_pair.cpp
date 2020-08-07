#include <iostream>
#include <utility>
using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
    return out<<'('<<p.first<<", "<<p.second<<')';
}

int main() {
    auto p1{make_pair("Hallo", 42)};
    cout << p1 << '\n';
    pair p2{"Dag", 24};
    cout << p2 << '\n';
}