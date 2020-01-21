#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int telop(int i, int j) {
    return i + j;
}

int main() {
    vector<int> v {-3, -4, 3, 4};
    vector<int> w {1, 2, 3, 4};
    ostream_iterator<int> iout {cout, " "};
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';
    copy(w.cbegin(), w.cend(), iout);
    cout << '\n';

//  Bewerking opgeven met een functie.
//  Nadeel: voor elke bewerking moet een aparte functie worden geschreven.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), telop);
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';

//  Bewerking opgeven met een lambda functie.
//  Voordeel: meest handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), [](int i1, int i2) {
        return i1 + i2;
    });
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';

//  Bewerking opgeven met een opgeslagen lambda functie.
//  Voordeel: meest handige oplossing als bewerking vaker voorkomt.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    auto add {[](int i1, int i2) {
        return i1 + i2;
    }};
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), add);
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';
}
