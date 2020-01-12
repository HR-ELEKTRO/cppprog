// Read-only variabelen definieren met const

#include <iostream>
using namespace std;

int main() {
    int i {3};
    const int j {24};
    
    // Een const die geïntialiseerd wordt met een compile time constant kan zelf ook als compile time constant gebruikt worden:
    [[maybe_unused]] int rij1[j];
    
    cout << "Geef i: ";
    cin >> i;
    
    // Een constante moet je initialiseren:
    // const int k;
    // Error: uninitialized const 'k'

    // Een const mag je initialiseren met een run time waarde
    [[maybe_unused]] const int m {i};
    // Een const die geïntialiseerd wordt met een variabele kan niet als compile time constant gebruikt worden:
    // int rij2[m];
    
    // Een constante mag je niet veranderen:
    // j = 7;
    // Error: assignment of read-only variable 'j'
}

