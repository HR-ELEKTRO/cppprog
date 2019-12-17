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
    cout << endl;

    // kopiëren van de een array
    auto b = a;
    for (auto e: b) {
        cout << e << " ";
    }
    cout << endl;
    // vergelijken van array's
    if (a != b)
        cout << "DIT KAN NIET!" << endl;

    // a[100] = 12;
    // ongeldige index ==> crash (als je geluk hebt!)
    // a.at(100) = 12;
    // ongeldige index ==> foutmelding (exception)

    cin.get();
    return 0;
}
