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
    cout << setw(2) << td.minuten << " minuten" << endl;
}

// Deze functie drukt een rij met een aantal gewerkte tijden af
void drukaf(Tijdsduur rij[], int aantal) {
    for (int teller = 0; teller < aantal; ++teller)
        drukaf(rij[teller]);
}

// Deze functie berekent de totaal gewerkte tijd uit een rij met een aantal gewerkte tijden
Tijdsduur som(Tijdsduur rij[], int aantal) {
    Tijdsduur s = {0, 0};
    for (int teller = 0; teller < aantal; ++teller) {
        s.uur += rij[teller].uur;
        s.minuten += rij[teller].minuten;
    }
    s.uur += s.minuten / 60;
    s.minuten %= 60;
    return s;
}

int main() {
    constexpr int MAX = 5;
    Tijdsduur gewerkteTijdenRij[MAX];
    int aantal = 0;
    do {
        cout << "Type gewerkte uren en minuten in (of Ctrl-Z): ";
        cin >> gewerkteTijdenRij[aantal].uur >> gewerkteTijdenRij[aantal].minuten;
    }
    while (cin && ++aantal < MAX);
    cout << endl << endl;
    drukaf(gewerkteTijdenRij, aantal);
    cout << "De totaal gewerkte tijd is:" << endl;
    drukaf(som(gewerkteTijdenRij, aantal));
    cin.get(); cin.clear(); cin.get();
    return 0;
}
