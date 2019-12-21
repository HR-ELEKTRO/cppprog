#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    list<int> l{12, 18, 6};
//  sort(l.begin(), l.end()); // O(n log n) heeft random access iteratoren nodig lijst levert bidirectionele iteratoren
//  Error (38 regels) belangrijkste mededeling:
//  no match for ‘operator-’ (operand types are ‘std::_List_iterator<int>’ and ‘std::_List_iterator<int>’)

    l.sort(); // O(n log n)
    for (auto e: l)
        cout << e << " ";
    cout << '\n';
    
    set<int> s{12, 6, 18};
    for (auto e: s)
        cout << e << " ";
    cout << '\n';
    
    auto i1{find(s.cbegin(), s.cend(), 6)}; // O(n)
    if (i1 != s.cend())
        cout << *i1 << " gevonden\n";
    auto i2{s.find(6)}; // O(log n)
    if (i2 != s.cend())
        cout << *i2 << " gevonden\n";
}
