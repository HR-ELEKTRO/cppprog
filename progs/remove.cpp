#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i * i);
    }
    vector<int> w(v);
        
//  code om te laten zien hoe remove werkt:
    ostream_iterator<int> out(cout, " ");
    cout << "Na initialisatie:" << endl;
    copy(v.cbegin(), v.cend(), out);
    auto end = remove_if(v.begin(), v.end(), [](int i) {
        return i % 2 == 0;
    });
    cout << endl << "Na remove (tot returned iterator):" << endl;
    copy(v.begin(), end, out);
    cout << endl << "Na remove (hele vector):" << endl;
    copy(v.cbegin(), v.cend(), out);
    v.erase(end, v.end());
    cout << endl << "Na erase (hele vector):" << endl;
    copy(v.cbegin(), v.cend(), out);

//  in de praktijk gebruiken we een remove altijd binnen een erase:
    w.erase(remove_if(w.begin(), w.end(), [](int i) {
        return i % 2 == 0;
    }), w.end());
    cout << endl << "Na remove binnen erase:" << endl;
    copy(w.cbegin(), w.cend(), out);

    cin.get();
    return 0;
}
