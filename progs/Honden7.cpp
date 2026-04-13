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

class Roedel {
public:
    void voeg_toe(Hond& h);
    void blaf_allemaal() const;
private:
    vector<Hond*> honden;
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

void Roedel::voeg_toe(Hond& h) {
    honden.push_back(&h);
}

void Roedel::blaf_allemaal() const {
    for (auto hp: honden) {
        hp->blaf();
    }
}

int main() {
    Sint_bernard h1 {"Boris", 10};
    Teckel h2 {"Fikkie"};
    Teckel h3 {"Harry"};

    Roedel r;
    r.voeg_toe(h1);
    r.voeg_toe(h2);
    r.voeg_toe(h3);

    r.blaf_allemaal();
}

/* Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
Hoera, Fikkie is geboren!
Er is een Teckel geboren!
Hoera, Harry is geboren!
Er is een Teckel geboren!
WOEF, WOEF
Kef kef
Kef kef
Er is een Teckel gestorven.
Helaas, Harry is gestorven.
Er is een Teckel gestorven.
Helaas, Fikkie is gestorven.
Er is een Sint_bernard gestorven.
Vat met 10 borrels opgeruimd.
Helaas, Boris is gestorven.
*/
