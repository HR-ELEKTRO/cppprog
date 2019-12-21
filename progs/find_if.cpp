#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

bool isPos(int i) {
    return i >= 0;
}

template<typename T>
class IsGreaterEqual {
public:
    IsGreaterEqual(int r): right(r) {
    }
    bool operator()(int left) const {
        return left >= right;
    }
private:
    T right;
};

int main() {
    list<int> l{-3, -4, 3, 4};
//  Zoeken met behulp van een functie als zoekvoorwaarde.
//  Nadeel: voor elke zoekvoorwaarde moet een aparte 
//  functie worden geschreven.
    auto r{find_if(l.cbegin(), l.cend(), isPos)};
    if (r != l.cend()) {
        cout << "Het eerste positieve element is: " << *r << '\n';
    }
//  Zoeken met behulp van een functie-object als zoekvoorwaarde.
//  Voordeel: flexibeler dan een functie.
//  Nadeel: voor elke vergelijkings operator moet een
//  apart functie-object worden geschreven.
    r = find_if(l.cbegin(), l.cend(), IsGreaterEqual<int>(0));
    if (r != l.cend()) {
        cout << "Het eerste positieve element is: " << *r << '\n';
    }
//  Zoeken met behulp van een lambda functie als zoekvoorwaarde.
//  Voordeel: handig als zoekvoorwaarde uniek is.
//  Nadeel: geen hergebruik mogelijk.
    r = find_if(l.cbegin(), l.cend(), [](int i) {
        return i >= 0;
    });
    if (r != l.end()) {
        cout << "Het eerste positieve element is: " << *r << '\n';
    }
}
