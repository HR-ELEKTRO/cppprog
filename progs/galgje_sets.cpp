#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string w{"galgje"};
    set<char> te_raden, geraden;
    copy(w.begin(), w.end(), inserter(te_raden, te_raden.begin()));
    do {
        for (auto c: w) {
            cout << (geraden.count(c) ? c : '.');
        }
        cout << "\nRaad een letter: ";
        char c{static_cast<char>(cin.get())}; cin.get();
        while (!geraden.insert(c).second) {
            cout << "De letter " << c << " had je al geraden...";
            cout << endl << "Raad een andere letter: ";
            c = cin.get(); cin.get();
        }
    } while (!includes(geraden.begin(), geraden.end(), te_raden.begin(), te_raden.end()));
    cout << "Je hebt het woord " << w << " geraden.\n";
}

