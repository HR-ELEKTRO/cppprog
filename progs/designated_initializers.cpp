import std;
using namespace std;

struct Persoon {
    string roepnaam;
    vector<string> doopnamen;
    string tussenvoegsel {""};
    string familienaam;
    int geboortedag {0};
    int geboortemaand {0};
    int geboortejaar {0};
    int lengte {0};
};

// De datamembers die een defaultwaarde hebben, kunnen worden overgeslagen in de
// designated initializer zonder dat de compiler een warning geeft.

void println(const Persoon& p) {
    print("{}", p.roepnaam);
    if (p.doopnamen.size() > 0 && !(p.doopnamen.size() == 1 && p.doopnamen[0] == p.roepnaam)) {
        print(" {::}", p.doopnamen);
    }
    if (!p.tussenvoegsel.empty()) {
        print(" {}", p.tussenvoegsel);
    }
    print(" {}", p.familienaam);
    if (p.geboortedag > 0 && p.geboortemaand > 0 && p.geboortejaar > 0) {
        print(" is geboren op {}/{}/{}", p.geboortedag, p.geboortemaand, p.geboortejaar);
        if (p.lengte > 0) {
            print(" en", p.lengte);
        }
    }
    if (p.lengte > 0) {
        print(" is {} cm lang", p.lengte);
    }
    println("");
}

int main() {
    // positional initialization:
    Persoon paula {"Paula", {"Paula"}, "van der", "Berg", 3, 5, 1990};
    Persoon klaas {"Klaas", {"Klaas"}, "", "Pieterse", 0, 0, 0, 180};
    // designated initialization:
    Persoon harry {
        .roepnaam="Harry", 
        .doopnamen={"Johannis", "Zacharias", "Maria"}, 
        .familienaam="Broeders", 
        .geboortedag=24, 
        .geboortemaand=12, 
        .geboortejaar=1962, 
        .lengte=184
    };
    /* more clear than:
    Persoon harry {"Harry", {"Johannis", "Zacharias", "Maria"}, "", "Broeders", 24, 12, 1962, 184};
    */
    Persoon marie_louise {
        .roepnaam="Marie-Louise", 
        .doopnamen={"Aloisia", "Cornelia", "Maria"}, 
        .tussenvoegsel="van", 
        .familienaam="Vugt",
        .lengte=170
    };
    println(paula);
    println(klaas);
    println(harry);
    println(marie_louise);
}