#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    virtual ~Hond();
    void set_naam(const string& n);
    virtual void blaf() const;
private:
    string naam;
};

class Tekkel: public Hond {
public:
    Tekkel(const string& n);
    virtual ~Tekkel();
    virtual void blaft() const; // OOPS foutje
//  Beter alternatief:
//  virtual void blaft() const override ; // foutje wordt nu door de compiler gemeld:
//  Error: 'virtual void Tekkel::blaft() const' marked override, but does not override
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

Tekkel::Tekkel(const string& n): Hond{n} {
    cout << "Er is een Tekkel geboren!\n";
}

Tekkel::~Tekkel() {
    cout << "Er is een Tekkel gestorven.\n";
}

void Tekkel::blaft() const {
    cout << "Kef kef\n";
}

int main() {
    Tekkel h1{"Biefie"};
    h1.blaf();
}

/* Uitvoer: 
Hoera, Biefie is geboren!
Er is een Tekkel geboren!
Blaf blaf
Er is een Tekkel gestorven.
Helaas, Biefie is gestorven.
*/