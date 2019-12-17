#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string w = "galgje";
    string geraden(w.length(), '.');
    do {
        cout << geraden << endl << "Raad een letter: ";
        char c = cin.get(); cin.get();
        transform(w.cbegin(), w.cend(), geraden.cbegin(), geraden.begin(), [c](char cw, char cg) {
            return c == cw ? cw : cg;
        });
    }
    while (geraden != w);
    cout << "Je hebt het woord \"" << w << "\" geraden." << endl;
    cin.get();
    return 0;
}

