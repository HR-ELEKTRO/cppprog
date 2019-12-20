// Dynamic binding werkt niet in de constructor en destructor

#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    Fruit() {
        cout << "Er is een " << soort() << " aangemaakt.\n";
    }
    virtual ~Fruit() {
        cout << "Er is een " << soort() << " verwijderd.\n";
    }
    virtual void print(ostream& o) {
        o << soort() << '\n';
    }
private:
    virtual string soort() const {
        return "Fruit";
    }
};

class Appel: public Fruit {
public:
    virtual string soort() const {
        return "Appel";
    }
//  ...
};

class Peer: public Fruit {
public:
    virtual string soort() const {
        return "Peer";
    }
//  ...
};

int main() {
    {
        Fruit f;
        f.print(cout);
        Appel a;
        a.print(cout);
        Peer p;
        p.print(cout);
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
