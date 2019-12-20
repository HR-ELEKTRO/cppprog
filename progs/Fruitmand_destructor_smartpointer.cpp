// Voorbeeld van gebruik van ABC, virtual destructor, polymorphism en smart pointers

#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
    void voegToe(unique_ptr<Fruit> p) {
        fp.push_back(move(p));
    }
    void printInhoud() const {
        cout << "De fruitmand bevat:\n";
        for (const auto& e: fp)
            cout << e->soort() << endl;
    }
private:
    vector<unique_ptr<Fruit>> fp;
};

int main() {
    FruitMand m;
    m.voegToe(make_unique<Appel>());
    m.voegToe(make_unique<Peer>());
    m.voegToe(make_unique<Appel>());
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
