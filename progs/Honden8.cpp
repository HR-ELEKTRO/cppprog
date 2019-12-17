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

WhiskeyVat::WhiskeyVat(int b): aantalBorrels(b) {
    cout << "Vat met " << aantalBorrels << " borrels aangemaakt." << endl;
}

WhiskeyVat::~WhiskeyVat() {
    cout << "Vat met " << aantalBorrels << " borrels opgeruimd." << endl;
}

bool WhiskeyVat::geefBorrel() {
    if (aantalBorrels > 0) {
        --aantalBorrels;
        cout << "Ik kom je helpen, drink deze borrel maar op!" << endl;
        return true;
    }
    cout << "Ik kan je niet helpen, mijn whiskey is op." << endl;
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

Hond::Hond(const string& n): naam(n) {
    cout << "Hoera, " << naam << " is geboren!" << endl;
}

Hond::~Hond() {
    cout << "Helaas, " << naam << " is gestorven." << endl;
    cin.get();
}

void Hond::setNaam(const string& n) {
    naam = n;
}

Tekkel::Tekkel(const string& n): Hond(n) {
    cout << "Er is een Tekkel geboren!" << endl;
}

Tekkel::~Tekkel() {
    cout << "Er is een Tekkel gestorven." << endl;
}

void Tekkel::blaf() const {
    cout << "Kef kef" << endl;
}

SintBernard::SintBernard(const string& n): Hond(n), vatPtr(0) {
    cout << "Er is een SintBernard geboren!" << endl;
}

SintBernard::SintBernard(const string& n, int b): Hond(n), vatPtr(new WhiskeyVat(b)) {
    cout << "Er is een SintBernard geboren!" << endl;
}

SintBernard::SintBernard(const SintBernard& s): Hond(s), vatPtr(0) {
    if (s.vatPtr != 0) {
        vatPtr = new WhiskeyVat(*(s.vatPtr));
    }
    cout << "Er is een SintBernard gekopieerd!" << endl;
}

SintBernard::~SintBernard() {
    cout << "Er is een SintBernard bijna dood." << endl;
    if (vatPtr != 0) {
        while (vatPtr->geefBorrel()) /* drink alle borrels op */;
    }
    delete vatPtr;
    cout << "Er is een SintBernard gestorven." << endl;
}

SintBernard& SintBernard::operator=(const SintBernard& r) {
    SintBernard t(r);
    Hond::operator=(t);
    std::swap(vatPtr, t.vatPtr);
    return *this;
}

void SintBernard::blaf() const {
    cout << "WOEF, WOEF" << endl;
}

void SintBernard::help() {
    if (vatPtr != 0) {
        vatPtr->geefBorrel();
    }
    blaf();
}

int main() {
    SintBernard h1("Boris", 10);
    h1.help();
    SintBernard h2("BlauweKnoop");
    h2.help();
//  Maak een kopietje van h1
    SintBernard h3(h1);
    for (int i = 0; i < 5; ++i) {
        h3.help() /* help 5 keer */;
    }
    h1.help();
//  Doe een toekenning
    h3 = h2;
    h3.blaf();
    h3.help();
    cin.get();
    return 0;
}

/*
Uitvoer:
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
Vat met 0 borrels opgeruimd.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
<enter>
WOEF, WOEF
<enter>
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, Boris is gestorven.
<enter>
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
<enter>
Er is een SintBernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Vat met 0 borrels opgeruimd.
Er is een SintBernard gestorven.
Helaas, Boris is gestorven.
<enter>

Uitvoer ZONDER zelf gedefinieerde copy constructor en assignment operator:
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
<enter>
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
<enter>
Er is een SintBernard bijna dood.
Er is een SintBernard gestorven.
Helaas, BlauweKnoop is gestorven.
<enter>
Er is een SintBernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Vat met 0 borrels opgeruimd.
Er is een SintBernard gestorven.
Helaas, Boris is gestorven.
<enter>
*/
