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
    virtual void blaft() const; // OOPS foutje
//  Beter alternatief:
//  virtual void blaft() const override ; // foutje wordt nu door de compiler gemeld:
//  Microsoft Visual C++ error: 
//  'Tekkel::blaft' : method with override specifier 'override' did not override any base class methods    
//  GNU gcc error:  
//  'virtual void Tekkel::blaft() const' marked override, but does not override
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

void Hond::blaf() const {
    cout << "Blaf blaf" << endl;
}

Tekkel::Tekkel(const string& n): Hond(n) {
    cout << "Er is een Tekkel geboren!" << endl;
}

Tekkel::~Tekkel() {
    cout << "Er is een Tekkel gestorven." << endl;
}

void Tekkel::blaft() const {
    cout << "Kef kef" << endl;
}

int main() {
    Tekkel h1("Biefie");
    h1.blaf();
    cin.get();
    return 0;
}

/* Uitvoer:
Hoera, Biefie is geboren!
Er is een Tekkel geboren!
Blaf blaf
<Enter>
Er is een Tekkel gestorven.
Helaas, Biefie is gestorven.
*/