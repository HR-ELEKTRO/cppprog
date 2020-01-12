// Constante definieren met constexpr i.p.v. #define
#include <iostream>
using namespace std;

int main() {
    int i {3};
    constexpr int j {24};

    cout << "Geef i: ";
    cin >> i;

    // Een constexpr moet je initialiseren:
    // constexpr int k;
    // Error: uninitialized const 'k'

    // Een constexpr moet je initialiseren met een compile time constante
    // constexpr int m {i};
    // Error: the value of 'i' is not usable in a constant expression

    [[maybe_unused]] constexpr int n {j};

    // Een constexpr mag je niet veranderen:
    // j = 7;
    // Error: assignment of read-only variable 'j'
}

