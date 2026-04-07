// Voorbeeld van dynamic binding

import std;
using namespace std;

class Fruit {
public:
    virtual void print() {
        println("{}", soort());
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
    f.print();
    Appel a;
    a.print();
    Peer p;
    p.print();
//  ...
}

/* Uitvoer:
Fruit
Appel
Peer
*/
