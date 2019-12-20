// Read-only variabelen definieren met const

#include <iostream>
using namespace std;

int main() {
    int i = 3;
    const int j = 24;
    
    cout << "Geef i: ";
    cin >> i;
    
    // Een constante moet je initialiseren:
    // const int k;
    // Error: uninitialized const 'k'

    // Een const mag je initialiseren met een run time waarde
    const int m = i;

    // Een constante mag je niet veranderen:
    // j = 7;
    // Error: assignment of read-only variable 'j'
}

