// Raed-only variabelen definieren met const

#include <iostream>
using namespace std;

int main() {
    int i = 3;
    const int j = 24;
    
    cout << "Geef i: ";
    cin >> i;
    
    // Een constante moet je initialiseren:
    const int k;
    // Fout (Microsoft): 'k' : const object must be initialized if not extern
    // Fout (GCC):       uninitialized const 'k'

    // Een const mag je initialiseren met een run time waarde
    const int m = i;

    // Een constante mag je niet veranderen:
    j = 7;
    // Fout (Microsoft): 'j' : you cannot assign to a variable that is const
    // Fout (GCC):       assignment of read-only variable 'j'

    return 0;
}

