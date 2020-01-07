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

class Fruit_mand {
public:
    void voeg_toe(Fruit& p) {
        fp.push_back(&p);
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
    Fruit_mand m;
    Appel a1, a2;
    Peer p1;
    m.voeg_toe(a1);
    m.voeg_toe(p1);
    m.voeg_toe(a2);
    m.print_inhoud();
//  ...
}

/* Uitvoer:
De fruitmand bevat:
Appel
Peer
Appel
*/

