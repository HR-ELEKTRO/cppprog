#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    virtual ~Hond();
    void setNaam(const string& n);
    virtual void blaf() const =0;
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

WhiskeyVat::WhiskeyVat(int b): aantalBorrels{b} {
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
    SintBernard(const string& n); /* aanmaken van een SintBernard zonder WhiskeyVat */
    SintBernard(const string& n, int b); /* aanmaken van een SintBernard met WhiskeyVat gevuld met b borrels*/
    SintBernard(const SintBernard& s);
    virtual ~SintBernard();
    SintBernard& operator=(const SintBernard& r);
    virtual void blaf() const override;
    void help();
private:
    WhiskeyVat* vatPtr;
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

Tekkel::Tekkel(const string& n): Hond{n} {
    cout << "Er is een Tekkel geboren!\n";
}

Tekkel::~Tekkel() {
    cout << "Er is een Tekkel gestorven.\n";
}

void Tekkel::blaf() const {
    cout << "Kef kef\n";
}

SintBernard::SintBernard(const string& n): Hond{n}, vatPtr{nullptr} {
    cout << "Er is een SintBernard geboren!\n";
}

SintBernard::SintBernard(const string& n, int b): Hond{n}, vatPtr{new WhiskeyVat(b)} {
    cout << "Er is een SintBernard geboren!\n";
}

SintBernard::SintBernard(const SintBernard& s): Hond{s}, vatPtr{nullptr} {
    if (s.vatPtr != nullptr) {
        vatPtr = new WhiskeyVat(*(s.vatPtr));
    }
    cout << "Er is een SintBernard gekopieerd!\n";
}

SintBernard::~SintBernard() {
    cout << "Er is een SintBernard bijna dood.\n";
    if (vatPtr != 0) {
        while (vatPtr->geefBorrel()) 
            /* drink alle borrels op */;
    }
    delete vatPtr;
    cout << "Er is een SintBernard gestorven.\n";
}

SintBernard& SintBernard::operator=(const SintBernard& r) {
    SintBernard t(r);
    Hond::operator=(t);
    std::swap(vatPtr, t.vatPtr);
    return *this;
}

void SintBernard::blaf() const {
    cout << "WOEF, WOEF\n";
}

void SintBernard::help() {
    if (vatPtr != 0) {
        vatPtr->geefBorrel();
    }
    blaf();
}

int main() {
    SintBernard h1{"Boris", 10};
    h1.help();
    SintBernard h2{"BlauweKnoop"};
    h2.help();
//  Maak een kopietje van h1
    SintBernard h3{h1};
    for (int i = 0; i < 5; ++i) {
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
Er is een SintBernard geboren!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Hoera, BlauweKnoop is geboren!
Er is een SintBernard geboren!
WOEF, WOEF
Er is een SintBernard gekopieerd!
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
Er is een SintBernard gekopieerd!
Er is een SintBernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kan je niet helpen, mijn whiskey is op.
Vat met 0 borrels opgeruimd.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
WOEF, WOEF
WOEF, WOEF
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
Er is een SintBernard bijna dood.
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
Er is een SintBernard gestorven.
Helaas, Boris is gestorven.
*/

/* Uitvoer ZONDER zelf gedefinieerde copy constructor en assignment operator:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een SintBernard geboren!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Hoera, BlauweKnoop is geboren!
Er is een SintBernard geboren!
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
Helaas, BlauweKnoop is gestorven.
Helaas, BlauweKnoop is gestorven.
Helaas, Boris is gestorven.
*/
