#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v {-3, -4, 3, 4};
    vector<int> w {1, 2, 3, 4};
    ostream_iterator<int> iout {cout, " "};
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';
    copy(w.cbegin(), w.cend(), iout);
    cout << '\n';
    
//  Bewerking opgeven met een standaard functie-object.
//  Voordeel: hergebruik van standaardcomponenten.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), plus<int>());
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';
}
