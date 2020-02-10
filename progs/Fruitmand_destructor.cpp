// Voorbeeld van gebruik van ABC, virtual destructor en polymorphism

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Fruit {
public:
    virtual ~Fruit() {
        cout << "Er is een stuk Fruit verwijderd.\n";
    }
    virtual string soort() const = 0;
// ...
};

class Appel: public Fruit {
public:
    ~Appel() override {
        cout << "Er is een Appel verwijderd.\n";
    }
    string soort() const override {
        return "Appel";
    }
// ...
};

class Peer: public Fruit {
public:
    ~Peer() override {
        cout << "Er is een Peer verwijderd.\n";
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
        cout << "De fruitmand bevat:\n";
        for (const Fruit* e: fp)
            cout << e->soort() << '\n';
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

