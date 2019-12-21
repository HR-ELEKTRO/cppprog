#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string w{"galgje"};
    set<char> goedGeraden, letters;
    copy(w.cbegin(), w.cend(), inserter(letters, letters.begin()));
    do {
        for (auto c: w) {
            cout << (goedGeraden.count(c) ? c : '.');
        }
        cout << "\nRaad een letter: ";
        char c{static_cast<char>(cin.get())}; cin.get();
        if (letters.count(c)) {
            goedGeraden.insert(c);
        }
    } while (goedGeraden != letters);
    cout << "Je hebt het woord " << w << " geraden." << endl;
}

