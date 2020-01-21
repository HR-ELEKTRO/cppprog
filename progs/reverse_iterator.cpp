#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename I>
void print(I begin, I end) {
    for (I i {begin}; i != end; ++i) {
        cout << *i << " ";
    }
    cout << '\n';
}

int main() {
    vector<int> v {1, 5, 4, 8, 4, 5, 7, 3};
    print(v.cbegin(), v.cend());
    // vector van voor naar achter doorzoeken
    auto eerste_vijf {find(v.begin(), v.end(), 5)};
    if (eerste_vijf != v.end()) {
        *eerste_vijf = 7;
    }
    print(v.cbegin(), v.cend());
    // vector van achter naar voor doorzoeken
    auto laatste_vijf {find(v.rbegin(), v.rend(), 5)};
    if (laatste_vijf != v.rend()) {
        *laatste_vijf = 7;
    }
    print(v.cbegin(), v.cend());
    // vector in omgekeerde volgorde afdrukken
    print(v.crbegin(), v.crend());
}