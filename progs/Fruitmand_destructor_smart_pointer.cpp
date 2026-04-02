// Voorbeeld van gebruik van ABC, virtual destructor, polymorphism en smart pointers

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
    void voeg_toe(unique_ptr<Fruit> p) {
        fp.push_back(move(p));
    }
    void print_inhoud() const {
        println("De fruitmand bevat:");
        for (const auto& e: fp)
            println("  {}", e->soort());
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
