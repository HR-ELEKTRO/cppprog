#include <iostream>
#include <array>
using namespace std;

int main() {
    // definieer array van 15 integers
    array<int, 15> a;
    // vul met kwadraten
    int i = 0;
    for (auto& e: a) {
        e = i * i;
        ++i;
    }
    // druk af
    for (auto e: a) {
        cout << e << " ";
    }
    cout << '\n';

    // kopiëren van de een array
    auto b{a};
    for (auto e: b) {
        cout << e << " ";
    }
    cout << '\n';
    // vergelijken van array's
    if (a != b)
        cout << "DIT KAN NIET!\n";

    a[100] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
    try {
        a.at(100) = 12;
        // ongeldige index ==> foutmelding (exception)
    } catch(const out_of_range& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    a[10000] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
}

/* Uitvoer:
0 1 4 9 16 25 36 49 64 81 100 121 144 169 196
0 1 4 9 16 25 36 49 64 81 100 121 144 169 196
Error: array::at: __n (which is 100) >= _Nm (which is 15)
Segmentation fault (core dumped)
*/
