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
    void blaft() const override; // OOPS foutje
//  foutje wordt door de compiler gemeld:
//  Error: 'void Teckel::blaft() const' marked override, but does not override
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

void Teckel::blaft() const {
    cout << "Kef kef\n";
}

int main() {
    Teckel h1{"Biefie"};
    h1.blaf();
}

/* Uitvoer: 
Hoera, Biefie is geboren!
Er is een Teckel geboren!
Blaf blaf
Er is een Teckel gestorven.
Helaas, Biefie is gestorven.
*/