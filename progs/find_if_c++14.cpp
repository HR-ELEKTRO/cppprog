#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> l{-3, -4, 3, 4};
//  Zoeken met behulp van een lambda functie als zoekvoorwaarde.
//  Gebruik auto als parametertype (werkt niet voor C++11, wel voor C++14).
    auto r{find_if(l.cbegin(), l.cend(), [](auto i) {
            return i >= 0;
        })
    };
    if (r != l.end()) {
        cout << "Het eerste positieve element is: " << *r << '\n';
    }
}
