#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int telop(int i, int j) {
    return i + j;
}

int main() {
    vector<int> v = {-3, -4, 3, 4};
    vector<int> w = {1, 2, 3, 4};
    ostream_iterator<int> iout(cout, " ");
    copy(v.cbegin(), v.cend(), iout);
    cout << endl;
    copy(w.cbegin(), w.cend(), iout);
    cout << endl;

//  Bewerking opgeven met een lambda functie.
//  Gebruik auto als parametertype (werkt niet voor C++11, wel voor C++14).
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), [](auto i1, auto i2) {
        return i1 + i2;
    });
    copy(v.cbegin(), v.cend(), iout);
    cout << endl;

    cin.get();
    return 0;
}
