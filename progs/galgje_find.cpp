#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string w {"galgje"}; 
    vector<bool> gevonden (w.size(), false);
    do {
        for (string::size_type i {0}; i < w.size(); ++i) {
            cout << (gevonden[i] ? w[i] : '.');
        }
        cout << "\nRaad een letter: ";
        char c {static_cast<char>(cin.get())}; cin.get();
        auto itr {w.cbegin()};
        int count {0};
        while ((itr = find(itr, w.cend(), c)) != w.cend()) {
            gevonden[(itr - w.cbegin())] = true;
            ++itr;
            ++count;
        }
        cout << "De letter '" << c << "' komt " << count << " keer voor in het te raden woord.\n";
    }
    while (any_of(gevonden.cbegin(), gevonden.cend(), [](auto b) {
        return b == false;
    }));
    cout << "Je hebt het woord \"" << w << "\" geraden.\n";
}
