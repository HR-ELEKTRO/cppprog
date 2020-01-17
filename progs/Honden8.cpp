#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    virtual ~Hond();
    void set_naam(const string& n);
    virtual void blaf() const =0;
private:
    string naam;
};

class Tekkel: public Hond {
public:
    Tekkel(const string& n);
    ~Tekkel() override;
    void blaf() const override;
};

class Whiskey_vat {
public:
    Whiskey_vat(int b);
    ~Whiskey_vat();
    bool geef_borrel();
private:
    int aantal_borrels;
};

Whiskey_vat::Whiskey_vat(int b): aantal_borrels{b} {
    cout << "Vat met " << aantal_borrels << " borrels aangemaakt.\n";
}

Whiskey_vat::~Whiskey_vat() {
    cout << "Vat met " << aantal_borrels << " borrels opgeruimd.\n";
}

bool Whiskey_vat::geef_borrel() {
    if (aantal_borrels > 0) {
        --aantal_borrels;
        cout << "Ik kom je helpen, drink deze borrel maar op!\n";
        return true;
    }
    cout << "Ik kan je niet helpen, mijn whiskey is op.\n";
    return false;
}

class Sint_bernard: public Hond {
public:
    Sint_bernard(const string& n); /* aanmaken van een Sint_bernard zonder Whiskey_vat */
    Sint_bernard(const string& n, int b); /* aanmaken van een Sint_bernard met Whiskey_vat gevuld met b borrels*/
    Sint_bernard(const Sint_bernard& s);
    ~Sint_bernard() override;
    Sint_bernard& operator=(const Sint_bernard& r);
    void blaf() const override;
    void help();
private:
    Whiskey_vat* vat_ptr;
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

Tekkel::Tekkel(const string& n): Hond{n} {
    cout << "Er is een Tekkel geboren!\n";
}

Tekkel::~Tekkel() {
    cout << "Er is een Tekkel gestorven.\n";
}

void Tekkel::blaf() const {
    cout << "Kef kef\n";
}

Sint_bernard::Sint_bernard(const string& n): Hond{n}, vat_ptr{nullptr} {
    cout << "Er is een Sint_bernard geboren!\n";
}

Sint_bernard::Sint_bernard(const string& n, int b): Hond{n}, vat_ptr{new Whiskey_vat(b)} {
    cout << "Er is een Sint_bernard geboren!\n";
}

Sint_bernard::Sint_bernard(const Sint_bernard& s): Hond{s}, vat_ptr{nullptr} {
    if (s.vat_ptr != nullptr) {
        vat_ptr = new Whiskey_vat(*(s.vat_ptr));
    }
    cout << "Er is een Sint_bernard gekopieerd!\n";
}

Sint_bernard::~Sint_bernard() {
    cout << "Er is een Sint_bernard bijna dood.\n";
    if (vat_ptr != 0) {
        while (vat_ptr->geef_borrel()) 
            /* drink alle borrels op */;
    }
    delete vat_ptr;
    cout << "Er is een Sint_bernard gestorven.\n";
}

Sint_bernard& Sint_bernard::operator=(const Sint_bernard& r) {
    Sint_bernard t(r);
    Hond::operator=(t);
    std::swap(vat_ptr, t.vat_ptr);
    return *this;
}

void Sint_bernard::blaf() const {
    cout << "WOEF, WOEF\n";
}

void Sint_bernard::help() {
    if (vat_ptr != 0) {
        vat_ptr->geef_borrel();
    }
    blaf();
}

int main() {
    Sint_bernard h1{"Boris", 10};
    h1.help();
    Sint_bernard h2{"Blauwe_knoop"};
    h2.help();
//  Maak een kopietje van h1
    Sint_bernard h3{h1};
    for (int i {0}; i < 5; ++i) {
        h3.help() /* help 5 keer */;
    }
    h1.help();
//  Doe een toekenning
    h3 = h2;
    h3.blaf();
    h3.help();
}

/* Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Hoera, Blauwe_knoop is geboren!
Er is een Sint_bernard geboren!
WOEF, WOEF
Er is een Sint_bernard gekopieerd!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Er is een Sint_bernard gekopieerd!
Er is een Sint_bernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kan je niet helpen, mijn whiskey is op.
Vat met 0 borrels opgeruimd.
Er is een Sint_bernard gestorven.
Helaas, Blauwe_knoop is gestorven.
WOEF, WOEF
WOEF, WOEF
Er is een Sint_bernard bijna dood.
Er is een Sint_bernard gestorven.
Helaas, Blauwe_knoop is gestorven.
Er is een Sint_bernard bijna dood.
Er is een Sint_bernard gestorven.
Helaas, Blauwe_knoop is gestorven.
Er is een Sint_bernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kan je niet helpen, mijn whiskey is op.
Vat met 0 borrels opgeruimd.
Er is een Sint_bernard gestorven.
Helaas, Boris is gestorven.
*/

/* Uitvoer ZONDER zelf gedefinieerde copy constructor en assignment operator:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Hoera, Blauwe_knoop is geboren!
Er is een Sint_bernard geboren!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
WOEF, WOEF
WOEF, WOEF
Helaas, Blauwe_knoop is gestorven.
Helaas, Blauwe_knoop is gestorven.
Helaas, Boris is gestorven.
*/
