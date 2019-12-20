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
    virtual ~Appel() {
        cout << "Er is een Appel verwijderd.\n";
    }
    virtual string soort() const {
        return "Appel";
    }
// ...
};

class Peer: public Fruit {
public:
    virtual ~Peer() {
        cout << "Er is een Peer verwijderd.\n";
    }
    virtual string soort() const {
        return "Peer";
    }
// ...
};

class FruitMand {
public:
    ~FruitMand() {
        for (const Fruit* e: fp)
            delete e;
            // Als we de constructor in de class Fruit *NIET* virtual maken geeft de GCC C++ compiler een warning:
            // Warning: deleting object of abstract class type ‘Fruit’ which has non-virtual destructor will cause undefined behavior
    }
    void voegToe(Fruit* p) {
        fp.push_back(p);
    }
    void printInhoud() const {
        cout << "De fruitmand bevat:\n";
        for (const Fruit* e: fp)
            cout << e->soort() << '\n';
    }
private:
    vector<Fruit*> fp;
};

int main() {
    FruitMand m;
    m.voegToe(new Appel);
    m.voegToe(new Peer);
    m.voegToe(new Appel);
    m.printInhoud();
    // hier wordt de Fruitmand m verwijderd!
}

/* Uitvoer:
De fruitmand bevat:
Appel
Peer
Appel
Er is een Appel verwijderd.
Er is een stuk Fruit verwijderd.
Er is een Peer verwijderd.
Er is een stuk Fruit verwijderd.
Er is een Appel verwijderd.
Er is een stuk Fruit verwijderd.
*/

// Als we de constructor in de class Fruit *NIET* virtual maken:
/* Uitvoer:
De fruitmand bevat:
Appel
Peer
Appel
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
*/
