#include <iostream>
using namespace std;

// de functie print kan gebruikt worden om integers af te drukken in elk willekerurig talstelsel
// default wordt het 10-tallig stelsel gebruikt

void print_digit(int digit) {
    if (digit < 10) {
        cout << digit;
    } else {
        char letter {'A'};
        letter += digit - 10;
        cout << letter;
    }
}

void print(int i, int talstelsel = 10) {
    if (talstelsel < 2 || talstelsel > 36) {
        cerr << "talstelsel moet tussen 2 en 36 zijn.\n";
    }
    else {
        if (i > talstelsel) {
            print(i/talstelsel, talstelsel);
        }
        print_digit(i % talstelsel);
    }
}

int main() {
    cout << "12 in het binaire talstelsel = ";
    print(12, 2);
    cout << "\n12 in het decimale talstelsel = ";
    print(12);
    cout << "\n12 in het decimale talstelsel = ";
    print(12, 10);
    cout << "\n12 in het hexadecimale talstelsel = ";
    print(12, 16);
    cout << "\n12 in het 7-tallig stelsel = ";
    print(12, 7);
    cout << "\n\n";

    int getal {123456789};
    for (int t = 2; t < 37; ++t) {
        cout << getal << " in het " << t << "-tallig stelsel = ";
        print(getal, t);
        cout << '\n';
    }
}
