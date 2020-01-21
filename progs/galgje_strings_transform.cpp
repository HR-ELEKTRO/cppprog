#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string w {"galgje"};
    string geraden (w.length(), '.');
    do {
        cout << geraden << "\nRaad een letter: ";
        char c {static_cast<char>(cin.get())}; cin.get();
        transform(w.cbegin(), w.cend(), geraden.cbegin(), geraden.begin(), [c](char cw, char cg) {
            return c == cw ? cw : cg;
        });
        cout << "De letter '" << c << "' komt " << count(w.cbegin(), w.cend(), c) << " keer voor in het te raden woord.\n";
    }
    while (geraden != w);
    cout << "Je hebt het woord \"" << w << "\" geraden.\n";
}
