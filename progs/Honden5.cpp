#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    virtual ~Hond();
    void setNaam(const string& n);
    virtual void blaf() const;
private:
    string naam;
};

class Tekkel: public Hond {
public:
    Tekkel(const string& n);
    virtual ~Tekkel();
    virtual void blaf() const override;
};

class WhiskeyVat {
public:
    WhiskeyVat(int b);
    ~WhiskeyVat();
    bool geefBorrel();
private:
    int aantalBorrels;
};

WhiskeyVat::WhiskeyVat(int b): aantalBorrels(b) {
    cout << "Vat met " << aantalBorrels << " borrels aangemaakt.\n";
}

WhiskeyVat::~WhiskeyVat() {
    cout << "Vat met " << aantalBorrels << " borrels opgeruimd.\n";
}

bool WhiskeyVat::geefBorrel() {
    if (aantalBorrels > 0) {
        --aantalBorrels;
        cout << "Ik kom je helpen, drink deze borrel maar op!\n";
        return true;
    }
    cout << "Ik kan je niet helpen, mijn whiskey is op.\n";
    return false;
}

class SintBernard: public Hond {
public:
    SintBernard(const string& n, int b);
    virtual ~SintBernard();
    virtual void blaf() const override;
    void help();
private:
    WhiskeyVat vat;
};

Hond::Hond(const string& n): naam{n} {
    cout << "Hoera, " << naam << " is geboren!\n";
}

Hond::~Hond() {
    cout << "Helaas, " << naam << " is gestorven.\n";
}

void Hond::setNaam(const string& n) {
    naam = n;
}

void Hond::blaf() const {
    cout << "Blaf blaf\n";
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

SintBernard::SintBernard(const string& n, int b): Hond{n}, vat{b} {
    cout << "Er is een SintBernard geboren!\n";
}

SintBernard::~SintBernard() {
    cout << "Er is een SintBernard gestorven.\n";
}

void SintBernard::blaf() const {
    cout << "WOEF, WOEF\n";
}

void SintBernard::help() {
    vat.geefBorrel();
    blaf();
}

int main() {
    SintBernard h1{"Boris", 10};
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
Er is een SintBernard geboren!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Blaf blaf
WOEF, WOEF
Helaas, Boris is gestorven.
Er is een SintBernard gestorven.
Vat met 9 borrels opgeruimd.
Helaas, Boris is gestorven.
*/
