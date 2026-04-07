// Dynamic binding werkt niet in de constructor en destructor

import std;
using namespace std;

class Fruit {
public:
    Fruit() {
        println("Er is een {} aangemaakt.", soort());
    }
    virtual ~Fruit() {
        println("Er is een {} verwijderd.", soort());
    }
    virtual void print() {
        println("{}", soort());
    }
private:
    virtual string soort() const {
        return "Fruit";
    }
};

class Appel: public Fruit {
public:
    string soort() const override {
        return "Appel";
    }
//  ...
};

class Peer: public Fruit {
public:
    string soort() const override {
        return "Peer";
    }
//  ...
};

int main() {
    {
        Fruit f;
        f.print();
        Appel a;
        a.print();
        Peer p;
        p.print();
    } // hier worden f, a en p verwijderd
}

/* Uitvoer:
Er is een Fruit aangemaakt.
Fruit
Er is een Fruit aangemaakt.
Appel
Er is een Fruit aangemaakt.
Peer
Er is een Fruit verwijderd.
Er is een Fruit verwijderd.
Er is een Fruit verwijderd.
*/
