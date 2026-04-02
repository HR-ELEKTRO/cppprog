// Voorbeeld van gebruik van ABC, virtual destructor en polymorphism

import std;
using namespace std;

class Fruit {
public:
    virtual ~Fruit() {
        println("Er is een stuk Fruit verwijderd.");
    }
    virtual string soort() const = 0;
// ...
};

class Appel: public Fruit {
public:
    ~Appel() override {
        println("Er is een Appel verwijderd.");
    }
    string soort() const override {
        return "Appel";
    }
// ...
};

class Peer: public Fruit {
public:
    ~Peer() override {
        println("Er is een Peer verwijderd.");
    }
    string soort() const override {
        return "Peer";
    }
// ...
};

class Fruitmand {
public:
    ~Fruitmand() {
        for (const Fruit* e: fp)
            delete e;
            // Als we de constructor in de class Fruit *NIET* virtual maken en *NIET* overridden voor Appel en Peer, dan geeft de GCC C++ compiler een warning:: deleting object of abstract class type 'Fruit' which has non-virtual destructor will cause undefined behavior
    }
    void voeg_toe(Fruit* p) {
        fp.push_back(p);
    }
    void print_inhoud() const {
        println("De fruitmand bevat:");
        for (const Fruit* e: fp)
            println("  {}", e->soort());
    }
private:
    vector<Fruit*> fp;
};

int main() {
    Fruitmand m;
    m.voeg_toe(new Appel);
    m.voeg_toe(new Appel);
    m.voeg_toe(new Peer);
    m.print_inhoud();
    // hier wordt de Fruitmand m verwijderd!
}

/* Uitvoer:
De fruitmand bevat:
  Appel
  Appel
  Peer
Er is een Appel verwijderd.
Er is een stuk Fruit verwijderd.
Er is een Appel verwijderd.
Er is een stuk Fruit verwijderd.
Er is een Peer verwijderd.
Er is een stuk Fruit verwijderd.
*/

// Als we de constructor in de class Fruit *NIET* virtual maken:
/* Uitvoer:
De fruitmand bevat:
  Appel
  Appel
  Peer
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
*/

