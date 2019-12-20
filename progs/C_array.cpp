#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

struct Tijdsduur { // Een Tijdsduur bestaat uit:
    int uur;       //    een aantal uren en
    int minuten;   //    een aantal minuten.
};

// Deze functie drukt een Tijdsduur af
void drukaf(Tijdsduur td) {
    if (td.uur == 0)
        cout<<"           ";
    else
        cout << setw(3) << td.uur << " uur en ";
    cout << setw(2) << td.minuten << " minuten" << '\n';
}

// Deze functie drukt een rij met Tijdsduren af
void drukaf(array<Tijdsduur, 5> rij) {
    for (auto t: rij)
        drukaf(t);
}

// Deze functie berekent de totaal Tijdsduur van een rij met Tijdsduren
auto som(array<Tijdsduur, 5> rij) {
    Tijdsduur s{0, 0};
    for (auto t: rij) {
        s.uur += t.uur;
        s.minuten += t.minuten;
    }
    s.uur += s.minuten / 60;
    s.minuten %= 60;
    return s;
}

int main() {
    array<Tijdsduur, 5> tijdsduur;
    array<Tijdsduur, 5>::size_type aantal = 0;
    do {
        cout << "Type uren en minuten in: ";
        cin >> tijdsduur[aantal].uur >> tijdsduur[aantal].minuten;
    }
    while (cin && ++aantal < tijdsduur.size());
    cout << '\n';
    drukaf(tijdsduur);
    cout << "De totaal tijdsduur is:\n";
    drukaf(som(tijdsduur));
}
