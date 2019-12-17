#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    list<int> l = {12, 18, 6};
//  sort(l.begin(), l.end()); // O(n log n) heeft random access iteratoren nodig lijst levert bidirectionele iteratoren
/*
    VS2013 error (16 regels) belangrijkset mededeling:
    binary '-' : 'std::_List_iterator<std::_List_val<std::_List_simple_types<int>>>' does not define this 
    operator or a conversion to a type acceptable to the predefined operator

    GCC error (58 regels) belangrijkste mededeling:
    In instantiation of 'void std::sort(_RAIter, _RAIter) [with _RAIter = std::_List_iterator<int>]':
    error: no match for 'operator-' in '__last - __first'
*/

    l.sort(); // O(n log n)
    for (auto e: l)
        cout << e << " ";
    cout << endl;
    
    set<int> s = {12, 6, 18};
    for (auto e: s)
        cout << e << " ";
    cout << endl;
    
    auto i1 = find(s.cbegin(), s.cend(), 6); // O(n)
    if (i1 != s.cend())
        cout << *i1 << " gevonden" << endl;
    auto i2 = s.find(6); // O(log n)
    if (i2 != s.end())
        cout << *i2 << " gevonden" << endl;

    cin.get();
    return 0;
}
