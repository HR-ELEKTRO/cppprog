#include <iostream>
#include <vector>
using namespace std;

int main() {
    // definieer vector van integers
    vector<int> v;
    // vul met kwadraten
    for (int i {0}; i < 15; ++i) {
        v.push_back(i * i);
    }
    // druk af
    for (auto e: v) {
        cout << e << " ";
    }
    cout << '\n';

    // kopiëren van een vector
    auto w {v};
    for (auto e: w) {
        cout << e << " ";
    }
    cout << '\n';
    // vergelijken van vectoren
    if (v != w)
        cout << "DIT KAN NIET!\n";

    v[100] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
    try {
        v.at(100) = 12;
        // ongeldige index ==> foutmelding (exception)
    } catch(const out_of_range& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    v[1000000] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
}

/* Uitvoer:
0 1 4 9 16 25 36 49 64 81 100 121 144 169 196
0 1 4 9 16 25 36 49 64 81 100 121 144 169 196
Error: vector::_M_range_check: __n (which is 100) >= this->size() (which is 15)
Segmentation fault (core dumped)
*/
