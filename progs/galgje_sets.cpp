#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string w {"galgje"};
    set<char> te_raden, geraden;
    copy(w.begin(), w.end(), inserter(te_raden, te_raden.begin()));
    do {
        for (auto c: w) {
            cout << (geraden.count(c) ? c : '.');
        }
        cout << "\nRaad een letter: ";
        char c {static_cast<char>(cin.get())}; cin.get();
        while (!geraden.insert(c).second) {
            cout << "De letter " << c << " had je al geraden...";
            cout << "\nRaad een andere letter: ";
            c = cin.get(); cin.get();
        }
        cout << "De letter '" << c << "' komt " << count(w.cbegin(), w.cend(), c) << " keer voor in het te raden woord.\n";
    } while (!includes(geraden.begin(), geraden.end(), te_raden.begin(), te_raden.end()));
    cout << "Je hebt het woord " << w << " geraden.\n";
}
