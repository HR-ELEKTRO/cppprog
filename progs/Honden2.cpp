import std;
using namespace std;

class Hond {
public:
    explicit Hond(string_view n);
    ~Hond();
    void set_naam(string_view n);
    void blaf() const;
private:
    string naam;
};

class Teckel: public Hond {
public:
    explicit Teckel(string_view n);
    ~Teckel();
    void blaf() const;
};

Hond::Hond(string_view n): naam {n} {
    println("Hoera, {} is geboren!", naam);
}

Hond::~Hond() {
    println("Helaas, {} is gestorven.", naam);
}

void Hond::set_naam(string_view n) {
    naam = n;
}

void Hond::blaf() const {
    println("Blaf blaf");
}

Teckel::Teckel(string_view n): Hond {n} {
    println("Er is een Teckel geboren!");
}

Teckel::~Teckel() {
    println("Er is een Teckel gestorven.");
}

void Teckel::blaf() const {
    println("Kef kef");
}

int main() {
    Hond h1 {"Fikkie"};
    h1.blaf();
    Teckel h2 {"Biefie"};
    h2.blaf();
    Teckel h3 {"Harry"};
    Hond& hr {h3};
    hr.blaf();
    Hond* hp {new Teckel("dynamic_Harry")};
    hp->blaf();
    delete hp;
}

/* Uitvoer:
Kef kef
Hoera, Harry is geboren!
Er is een Teckel geboren!
Blaf blaf
Hoera, dynamic_Harry is geboren!
Er is een Teckel geboren!
Blaf blaf
Helaas, dynamic_Harry is gestorven.
Er is een Teckel gestorven.
Helaas, Harry is gestorven.
Er is een Teckel gestorven.
Helaas, Biefie is gestorven.
Helaas, Fikkie is gestorven.
*/
