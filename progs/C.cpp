#include <iostream>
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

// Deze functie drukt een rij met een aantal Tijdsduren af
void drukaf(const Tijdsduur rij[], size_t aantal) {
    for (size_t teller {0}; teller < aantal; ++teller)
        drukaf(rij[teller]);
}

// Deze functie berekent de totaal Tijdsduur van een rij met een aantal Tijdsduren
auto som(const Tijdsduur rij[], size_t aantal) {
    Tijdsduur s {0, 0};
    for (size_t teller {0}; teller < aantal; ++teller) {
        s.uur += rij[teller].uur;
        s.minuten += rij[teller].minuten;
    }
    s.uur += s.minuten / 60;
    s.minuten %= 60;
    return s;
}

int main() {
    constexpr size_t MAX_TIJDSDUREN {5};
    Tijdsduur tijdsduren[MAX_TIJDSDUREN];
    size_t aantal {0};
    do {
        cout << "Type uren en minuten in: ";
        cin >> tijdsduren[aantal].uur >> tijdsduren[aantal].minuten;
    }
    while (cin && ++aantal < MAX_TIJDSDUREN);
    cout << '\n';
    drukaf(tijdsduren, aantal);
    cout << "De totaal tijdsduur is:\n";
    drukaf(som(tijdsduren, aantal));
}
