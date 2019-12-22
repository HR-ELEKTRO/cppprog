#include <iostream>
#include <vector>
using namespace std;

void lees_ints(vector<int>& vec) {
    // gooi huidige inhoud vec weg
    vec.resize(0);
    int i;
    cout << "Voer een willekeurig aantal integers in, ";
    cout << "sluit af met een letter:\n";
    while (cin >> i) {
        vec.push_back(i);
    }
    // zorg dat cin na de "onjuiste" invoer weer gebruikt kan worden
    cin.clear();
    cin.get();
}

int main() {
    // definieer vector
    vector<int> v;
    // vul deze vector
    lees_ints(v);
    // druk af
    for (auto e: v) {
        cout << e << " ";
    }
    cout << '\n';
}
