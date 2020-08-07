#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    explicit Hond(const string& n);
    virtual ~Hond();
    void set_naam(const string& n);
    virtual void blaf() const;
private:
    string naam;
};

class Teckel: public Hond {
public:
    explicit Teckel(const string& n);
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

Whisky_vat::Whisky_vat(int b): aantal_borrels{b} {
    cout << "Vat met " << aantal_borrels << " borrels aangemaakt.\n";
}

Whisky_vat::~Whisky_vat() {
    cout << "Vat met " << aantal_borrels << " borrels opgeruimd.\n";
}

bool Whisky_vat::geef_borrel() {
    if (aantal_borrels > 0) {
        --aantal_borrels;
        cout << "Ik kom je helpen, drink deze borrel maar op!\n";
        return true;
    }
    cout << "Ik kan je niet helpen, mijn Whisky is op.\n";
    return false;
}

class Sint_bernard: public Hond {
public:
    Sint_bernard(const string& n, int b);
    ~Sint_bernard() override;
    void blaf() const override;
    void help();
private:
    Whisky_vat vat;
};

Hond::Hond(const string& n): naam{n} {
    cout << "Hoera, " << naam << " is geboren!\n";
}

Hond::~Hond() {
    cout << "Helaas, " << naam << " is gestorven.\n";
}

void Hond::set_naam(const string& n) {
    naam = n;
}

void Hond::blaf() const {
    cout << "Blaf blaf\n";
}

Teckel::Teckel(const string& n): Hond{n} {
    cout << "Er is een Teckel geboren!\n";
}

Teckel::~Teckel() {
    cout << "Er is een Teckel gestorven.\n";
}

void Teckel::blaf() const {
    cout << "Kef kef\n";
}

Sint_bernard::Sint_bernard(const string& n, int b): Hond{n}, vat{b} {
    cout << "Er is een Sint_bernard geboren!\n";
}

Sint_bernard::~Sint_bernard() {
    cout << "Er is een Sint_bernard gestorven.\n";
}

void Sint_bernard::blaf() const {
    cout << "WOEF, WOEF\n";
}

void Sint_bernard::help() {
    vat.geef_borrel();
    blaf();
}

int main() {
    Sint_bernard h1{"Boris", 10};
    h1.blaf();
    h1.help();
    Hond h2{h1};
    h2.blaf();
    Hond& h3{h1};
    h3.blaf();
}

/* Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Blaf blaf
WOEF, WOEF
Helaas, Boris is gestorven.
Er is een Sint_bernard gestorven.
Vat met 9 borrels opgeruimd.
Helaas, Boris is gestorven.
*/
