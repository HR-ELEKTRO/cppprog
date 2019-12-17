#include <iostream>
#include <string>
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
    SintBernard(const string& n, int b);
    virtual ~SintBernard();
    virtual void blaf() const override;
    void help();
private:
    WhiskeyVat vat;
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

SintBernard::SintBernard(const string& n, int b): Hond(n), vat(b) {
    cout << "Er is een SintBernard geboren!" << endl;
}

SintBernard::~SintBernard() {
    cout << "Er is een SintBernard gestorven." << endl;
}

void SintBernard::blaf() const {
    cout << "WOEF, WOEF" << endl;
}

void SintBernard::help() {
    vat.geefBorrel();
    blaf();
}

int main() {
    SintBernard h1("Boris", 10);
    h1.blaf();
    h1.help();
//    Hond h2(h1);
//    Error Microsoft Visual C++:
//        'Hond' : cannot instantiate abstract class
//          due to following members:
//        'void Hond::blaf(void) const' : is abstract
//    Error GCC gcc:
//        cannot declare variable `h2' to be of type `Hond'
//        because the following virtual functions are abstract:
//        virtual void Hond::blaf() const

    Hond& h3(h1);
    h3.blaf();
    cin.get();
    return 0;
}

/*
Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een SintBernard geboren!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
WOEF, WOEF
<enter>
Er is een SintBernard gestorven.
Vat met 9 borrels opgeruimd.
Helaas, Boris is gestorven.
<enter>
*/
