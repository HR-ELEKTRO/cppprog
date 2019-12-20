#include <iostream>
#include <vector>
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
void drukaf(vector<Tijdsduur> rij) {
    for (auto t: rij)
        drukaf(t);
}

// Deze functie berekent de totaal Tijdsduur van een rij met Tijdsduren
auto som(vector<Tijdsduur> rij) {
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
    vector<Tijdsduur> tijdsduur;
    do {
        Tijdsduur t;
        cout << "Type uren en minuten in: ";
        cin >> t.uur >> t.minuten;
        if (cin)
            tijdsduur.push_back(t);
    }
    while (cin);
    cout << '\n';
    drukaf(tijdsduur);
    cout << "De totaal tijdsduur is:\n";
    drukaf(som(tijdsduur));
}
