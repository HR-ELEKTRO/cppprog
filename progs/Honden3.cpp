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
    void blaf() const override;
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

void Teckel::blaf() const {
    cout << "Kef kef\n";
}

int main() {
    Hond h1{"Fikkie"};
    h1.blaf();
    Teckel h2{"Biefie"};
    h2.blaf();
    Hond* hp{new Teckel("Harry")};
    hp->blaf();
    delete hp;
}

/* Uitvoer:
Hoera, Fikkie is geboren!
Blaf blaf
Hoera, Biefie is geboren!
Er is een Teckel geboren!
Kef kef
Hoera, Harry is geboren!
Er is een Teckel geboren!
Kef kef
Er is een Teckel gestorven.
Helaas, Harry is gestorven.
Er is een Teckel gestorven.
Helaas, Biefie is gestorven.
Helaas, Fikkie is gestorven.
*/
