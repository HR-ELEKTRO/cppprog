import std;
using namespace std;

class Hond {
public:
    explicit Hond(string_view n);
    virtual ~Hond();
    void set_naam(string_view n);
    virtual void blaf() const =0;
private:
    string naam;
};

class Teckel: public Hond {
public:
    explicit Teckel(string_view n);
    ~Teckel() override;
    void blaf() const override;
};

class Whisky_vat {
public:
    explicit Whisky_vat(int b);
    ~Whisky_vat();
    bool geef_borrel();
private:
    int aantal_borrels;
};

Whisky_vat::Whisky_vat(int b): aantal_borrels {b} {
    println("Vat met {} borrels aangemaakt.", aantal_borrels);
}

Whisky_vat::~Whisky_vat() {
    println("Vat met {} borrels opgeruimd.", aantal_borrels);
}

bool Whisky_vat::geef_borrel() {
    if (aantal_borrels > 0) {
        --aantal_borrels;
        println("Ik kom je helpen, drink deze borrel maar op!");
        return true;
    }
    println("Ik kan je niet helpen, mijn Whisky is op.");
    return false;
}

class Sint_bernard: public Hond {
public:
    Sint_bernard(string_view n, int b);
    ~Sint_bernard() override;
    void blaf() const override;
    void help();
private:
    Whisky_vat vat;
};

Hond::Hond(string_view n): naam {n} {
    println("Hoera, {} is geboren!", naam);
}

Hond::~Hond() {
    println("Helaas, {} is gestorven.", naam);
}

void Hond::set_naam(string_view n) {
    naam = n;
}

Teckel::Teckel(string_view n): Hond {n} {
    println("Er is een Teckel geboren!");
}

Teckel::~Teckel() {
    println("Er is een Teckel gestorven.");
}

void Teckel::blaf() const {
    println("Kef kef");
}

Sint_bernard::Sint_bernard(string_view n, int b): Hond {n}, vat {b} {
    println("Er is een Sint_bernard geboren!");
}

Sint_bernard::~Sint_bernard() {
    println("Er is een Sint_bernard gestorven.");
}

void Sint_bernard::blaf() const {
    println("WOEF, WOEF");
}

void Sint_bernard::help() {
    vat.geef_borrel();
    blaf();
}

int main() {
    Sint_bernard h1 {"Boris", 10};
    h1.blaf();
    h1.help();
//  Hond h2 {h1};
//  error: cannot declare variable 'h2' to be of abstract type 'Hond'
//  note: because the following virtual functions are pure within 'Hond':
//  note: 'virtual void Hond::blaf() const'
    Hond& h3 {h1};
    h3.blaf();
}

/* Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
WOEF, WOEF
Er is een Sint_bernard gestorven.
Vat met 9 borrels opgeruimd.
Helaas, Boris is gestorven.
*/
