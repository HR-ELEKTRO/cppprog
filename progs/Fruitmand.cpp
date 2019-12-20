// Voorbeeld van gebruik van ABC, vector en polymorphism

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Fruit {
public:
    virtual string soort() const = 0;
// ...
};

class Appel: public Fruit {
public:
    virtual string soort() const {
        return "Appel";
    }
// ...
};

class Peer: public Fruit {
public:
    virtual string soort() const {
        return "Peer";
    }
// ...
};

class FruitMand {
public:
    void voegToe(Fruit& p) {
        fp.push_back(&p);
    }
    void printInhoud() const {
        cout << "De fruitmand bevat:\n";
        for (const Fruit* e: fp)
            cout << e->soort() << endl;
    }
private:
    vector<Fruit*> fp;
};

int main() {
    FruitMand m;
    Appel a1, a2;
    Peer p1;
    m.voegToe(a1);
    m.voegToe(p1);
    m.voegToe(a2);
    m.printInhoud();
//  ...
}

/* Uitvoer:
De fruitmand bevat:
Appel
Peer
Appel
*/

