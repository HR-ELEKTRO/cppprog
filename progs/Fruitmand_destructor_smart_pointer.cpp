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
    void voeg_toe(unique_ptr<Fruit> p) {
        fp.push_back(move(p));
    }
    void print_inhoud() const {
        cout << "De fruitmand bevat:\n";
        for (const auto& e: fp)
            cout << e->soort() << '\n';
    }
private:
    vector<unique_ptr<Fruit>> fp;
};

int main() {
    Fruitmand m;
    m.voeg_toe(make_unique<Appel>());
    m.voeg_toe(make_unique<Appel>());
    m.voeg_toe(make_unique<Peer>());
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

// Als we de destructor in de class Fruit *NIET* virtual maken:
/* Uitvoer:
De fruitmand bevat:
Appel
Appel
Peer
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
Er is een stuk Fruit verwijderd.
*/
