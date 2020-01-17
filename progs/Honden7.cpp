#include <iostream>
#include <string>
#include <vector>
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
    Sint_bernard(const string& n, int b);
    ~Sint_bernard() override;
    void blaf() const override;
    void help();
private:
    Whiskey_vat vat;
};

class Roedel {
public:
    void voeg_toe(Hond& h);
    void blaf_allemaal() const;
private:
    vector<Hond*> honden;
};

Hond::Hond(const string& n): naam(n) {
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

void Roedel::voeg_toe(Hond& h) {
    honden.push_back(&h);
}

void Roedel::blaf_allemaal() const {
    for (auto hp: honden) {
        hp->blaf();
    }
}

int main() {
    Sint_bernard h1{"Boris", 10};
    Tekkel h2{"Fikkie"};
    Tekkel h3{"Harry"};

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
Er is een Tekkel geboren!
Hoera, Harry is geboren!
Er is een Tekkel geboren!
WOEF, WOEF
Kef kef
Kef kef
Er is een Tekkel gestorven.
Helaas, Harry is gestorven.
Er is een Tekkel gestorven.
Helaas, Fikkie is gestorven.
Er is een Sint_bernard gestorven.
Vat met 10 borrels opgeruimd.
Helaas, Boris is gestorven.
*/
