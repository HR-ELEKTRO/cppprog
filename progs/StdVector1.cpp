#include <iostream>
#include <vector>
using namespace std;

int main() {
    // definieer vector van integers
    vector<int> v;
    // vul met kwadraten
    for (int i = 0; i < 15; ++i) {
        v.push_back(i * i);
    }
    // druk af
    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;

    // kopiëren van een vector
    auto w = v;
    for (auto e: w) {
        cout << e << " ";
    }
    cout << endl;
    // vergelijken van vectoren
    if (v != w)
        cout << "DIT KAN NIET!" << endl;

    // v[100] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
    // v.at(100) = 12;
    // ongeldige index ==> foutmelding (exception)

    cin.get();
    return 0;
}
