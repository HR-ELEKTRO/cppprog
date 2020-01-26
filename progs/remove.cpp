#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    for (int i {0}; i < 10; ++i) {
        v.push_back(i * i);
    }
    vector<int> w {v};
        
//  code om te laten zien hoe remove werkt:
    ostream_iterator<int> out {cout, " "};
    cout << "Na initialisatie:\n";
    copy(v.cbegin(), v.cend(), out);
    auto end {remove_if(v.begin(), v.end(), [](auto i) {
            return i % 2 == 0;
        })
    };
    cout << "\nNa remove (tot returned iterator):\n";
    copy(v.begin(), end, out);
    cout << "\nNa remove (hele vector):\n";
    copy(v.cbegin(), v.cend(), out);
    v.erase(end, v.end());
    cout << "\nNa erase (hele vector):\n";
    copy(v.cbegin(), v.cend(), out);

//  in de praktijk gebruiken we een remove altijd binnen een erase:
    w.erase(remove_if(w.begin(), w.end(), [](auto i) {
        return i % 2 == 0;
    }), w.end());
    cout << "\nNa remove binnen erase:\n";
    copy(w.cbegin(), w.cend(), out);
}
