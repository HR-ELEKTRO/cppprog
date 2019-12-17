#include <iostream>
#include <iomanip>
using namespace std;

struct Tijdsduur { // Een Tijdsduur bestaat uit:
    int uur;       //    een aantal uren en
    int min;       //    een aantal minuten.
};

// Deze functie drukt een Tijdsduur af
// Gebruik van const reference voorkomt maken van een onnodig kopietje
void drukaf(const Tijdsduur& td) {
    td.uur = 23;
    if (td.uur == 0)
        cout << "           ";
    else
        cout << setw(3) << td.uur << " uur en ";
    cout << setw(2) << td.min << " minuten" << endl;
}

int main () {
    Tijdsduur t = {12, 34};
    drukaf(t);
    cin.get();
    return 0;
}
