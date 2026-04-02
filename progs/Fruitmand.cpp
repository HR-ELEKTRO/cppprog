// Voorbeeld van gebruik van ABC, vector en polymorphism

import std;
using namespace std;

class Fruit {
public:
    virtual string soort() const = 0;
// ...
};

class Appel: public Fruit {
public:
    string soort() const override {
        return "Appel";
    }
// ...
};

class Peer: public Fruit {
public:
    string soort() const override {
        return "Peer";
    }
// ...
};

class Fruitmand {
public:
    void voeg_toe(Fruit& p) {
        fp.push_back(&p);
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
    Appel a1, a2;
    Peer p1;
    m.voeg_toe(a1);
    m.voeg_toe(a2);
    m.voeg_toe(p1);
    m.print_inhoud();
}

/* Uitvoer:
De fruitmand bevat:
  Appel
  Appel
  Peer
*/

