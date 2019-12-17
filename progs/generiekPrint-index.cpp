#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

// generieke print m.b.v. indexering
// kan ALLEEN gebruikt worden voor string, array, vector en deque
// kan NIET gebruikt worden voor andere containers (list, forward_list, enz)

template<typename C> void print(const C& c) {
    cout << "De inhoud van de container is:" << endl;
    for (decltype(c.size()) i = 0; i != c.size(); ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    deque<double> d;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        d.push_back(1.0 / i);
    }
    print(v);
    print(d);
    string s("Hallo");
    print(s);
    cin.get();
    return 0;
}
