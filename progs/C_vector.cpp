import std;
using namespace std;

struct Tijdsduur { // Een Tijdsduur bestaat uit:
    int uur;       //    een aantal uren en
    int minuten;   //    een aantal minuten.
};

// Deze functie drukt een Tijdsduur af
void drukaf(Tijdsduur td) {
    if (td.uur == 0)
        println("{:13} minuten", td.minuten);
    else
        println("{:3} uur en {:2} minuten", td.uur, td.minuten);
}

// Deze functie drukt een rij met Tijdsduren af
void drukaf(const vector<Tijdsduur>& rij) {
    for (auto t: rij)
        drukaf(t);
}

// Deze functie berekent de totale Tijdsduur van een rij met Tijdsduren
auto som(const vector<Tijdsduur>& rij) {
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
    vector<Tijdsduur> tijdsduren;
    do {
        Tijdsduur t;
        print("Type uren en minuten in: ");
        cin >> t.uur >> t.minuten;
        if (cin)
            tijdsduren.push_back(t);
    }
    while (cin);
    println();
    drukaf(tijdsduren);
    println("De totale tijdsduur is:");
    drukaf(som(tijdsduren));
}
