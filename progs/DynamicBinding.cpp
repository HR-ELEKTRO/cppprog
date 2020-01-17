// Voorbeeld van dynamic binding

#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    virtual void print(ostream& o) {
        o << soort() << '\n';
    }
private:
    virtual string soort() const {
        return "Fruit";
    }
//  ...
};

class Appel: public Fruit {
private:
    string soort() const override {
        return "Appel";
    }
//  ...
};

class Peer: public Fruit {
private:
    string soort() const override {
        return "Peer";
    }
//  ...
};

int main() {
    Fruit f;
    f.print(cout);
    Appel a;
    a.print(cout);
    Peer p;
    p.print(cout);
//  ...
}

/* Uitvoer:
Fruit
Appel
Peer
*/
