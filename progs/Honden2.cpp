#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    ~Hond();
    void setNaam(const string& n);
    void blaf() const;
private:
    string naam;
};

class Tekkel: public Hond {
public:
    Tekkel(const string& n);
    ~Tekkel();
    void blaf() const;
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

void Tekkel::blaf() const {
    cout << "Kef kef" << endl;
}

int main() {
    Hond h1("Fikkie");
    h1.blaf();
    Tekkel h2("Biefie");
    h2.blaf();
    Hond* hp(new Tekkel("Harry"));
    hp->blaf();
    delete hp;
    cin.get();
    return 0;
}

/*
Uitvoer:
Hoera, Fikkie is geboren!
Blaf blaf
Hoera, Biefie is geboren!
Er is een Tekkel geboren!
Kef kef
Hoera, Harry is geboren!
Er is een Tekkel geboren!
Blaf blaf
Helaas, Harry is gestorven.
<enter>
<enter>
Er is een Tekkel gestorven.
Helaas, Biefie is gestorven.
<enter>
Helaas, Fikkie is gestorven.
<enter>
*/
