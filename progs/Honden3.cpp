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
    virtual void blaf() const;
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

void Tekkel::blaf() const {
    cout << "Kef kef\n";
}

int main() {
    Hond h1{"Fikkie"};
    h1.blaf();
    Tekkel h2{"Biefie"};
    h2.blaf();
    Hond* hp{new Tekkel("Harry")};
    hp->blaf();
    delete hp;
}

/* Uitvoer:
Hoera, Fikkie is geboren!
Blaf blaf
Hoera, Biefie is geboren!
Er is een Tekkel geboren!
Kef kef
Hoera, Harry is geboren!
Er is een Tekkel geboren!
Kef kef
Er is een Tekkel gestorven.
Helaas, Harry is gestorven.
Er is een Tekkel gestorven.
Helaas, Biefie is gestorven.
Helaas, Fikkie is gestorven.
*/
