#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string w{"galgje"}; 
    vector<bool> gevonden(w.size(), false);
    do {
        for (string::size_type i{0}; i < w.size(); ++i) {
            cout << (gevonden[i] ? w[i] : '.');
        }
        cout << "\nRaad een letter: ";
        char c{static_cast<char>(cin.get())}; cin.get();
        auto itr{w.cbegin()};
        while ((itr = find(itr, w.cend(), c)) != w.cend()) {
            gevonden[(itr - w.cbegin())] = true;
            ++itr;
        }
    }
    while (count(gevonden.begin(), gevonden.end(), false) != 0);
    cout << "Je hebt het woord \"" << w << "\" geraden.\n";
}

