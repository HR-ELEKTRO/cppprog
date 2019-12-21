#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void printDubbel(int i) {
    cout << i << " " << i << " ";
}

int main() {
    vector<int> v{-3, -4, 3, 4};
    ostream_iterator<int> iout{cout, " "};
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';

//  Bewerking opgeven met een functie.
//  Nadeel: voor elke bewerking moet een aparte functie worden geschreven.
    for_each(v.cbegin(), v.cend(), printDubbel);
    cout << '\n';

//  Bewerking opgeven met een lambda functie.
//  Voordeel: handig als bewerking uniek is.
//  Nadeel: geen hergebruik mogelijk.
    for_each(v.cbegin(), v.cend(), [](int i) {
        cout << i << " " << i << " ";
    });
    cout << '\n';

//  Alternatief voor for_each met lambda functie: gebruik range-based for.
//  Voordeel: eenvoudigere syntax.
//  Nadeel: werkt alleen als de gehele container doorlopen moet worden,
//  for_each kan ook gebruikt worden om een deel van een container te 
//  doorlopen.
    for (auto i: v) {
        cout << i << " " << i << " ";
    };
    cout << '\n';
}
