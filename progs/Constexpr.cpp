// Constante definieren met constexpr i.p.v. #define
// Werkt niet in Microsoft Visual Studio 2013
// Werkt wel sinds GCC 4.6

#include <iostream>
using namespace std;

int main() {
    int i = 3;
    constexpr int j = 24;

    cout << "Geef i: ";
    cin >> i;

    // Een constexpr moet je initialiseren:
    constexpr int k;
    // Fout (GCC):       uninitialized const 'k'

    // Een constexpr moet je initialiseren met een compile time constante
    constexpr int m = i;
    // Fout (GCC):       the value of 'i' is not usable in a constant expression

    constexpr int n = j;

    // Een constexpr mag je niet veranderen:
    j = 7;
    // Fout (GCC):       assignment of read-only variable 'j'

    return 0;
}

