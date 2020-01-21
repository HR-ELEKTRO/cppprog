#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// generieke print met behulp van een range van twee iteratoren
// met deze functie kun je ook een DEEL van een container afdrukken

template <typename Iter> void print(Iter begin, Iter end) {
    cout << "De inhoud van de container is:\n";
    for (Iter iter {begin}; iter != end; ++iter) {
        cout << *iter << " ";
    }
    cout << '\n';
}

int main() {
    vector<int> v;
    list<double> l;
    for (int i {1}; i <= 10; ++i) {
        v.push_back(i);
        l.push_back(1.0 / i);
    }
    print(v.cbegin(), v.cend());
    print(v.cbegin() + 1, v.cend() - 1);
    print(l.cbegin(), l.cend());
    string s {"Hallo"};
    print(s.cbegin(), s.cend());
}
