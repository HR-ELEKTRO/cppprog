#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void print_dubbel(int i) {
    cout << i << " " << i << " ";
}

int main() {
    vector<int> v{-3, -4, 3, 4};
    ostream_iterator<int> iout {cout, " "};
    copy(v.cbegin(), v.cend(), iout);
    cout << '\n';

//  Bewerking opgeven met een functie.
//  Nadeel: voor elke bewerking moet een aparte functie worden geschreven.
    for_each(v.cbegin(), v.cend(), print_dubbel);
    cout << '\n';

//  Bewerking opgeven met een lambda functie.
//  Voordeel: meest handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    for_each(v.cbegin(), v.cend(), [](int i) {
        cout << i << " " << i << " ";
    });
    cout << '\n';

//  Bewerking opgeven met een opgeslagen lambda functie.
//  Voordeel: meest handige oplossing als bewerking vaker voorkomt.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    auto print_twice {[](int i) {
        cout << i << " " << i << " ";
    }};
    for_each(v.cbegin(), v.cend(), print_twice);
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
