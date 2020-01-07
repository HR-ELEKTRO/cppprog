#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string w{"galgje"};
    set<char> goed_geraden, letters;
    copy(w.cbegin(), w.cend(), inserter(letters, letters.begin()));
    do {
        for (auto c: w) {
            cout << (goed_geraden.count(c) ? c : '.');
        }
        cout << "\nRaad een letter: ";
        char c{static_cast<char>(cin.get())}; cin.get();
        if (letters.count(c)) {
            goed_geraden.insert(c);
        }
    } while (goed_geraden != letters);
    cout << "Je hebt het woord " << w << " geraden.\n";
}

