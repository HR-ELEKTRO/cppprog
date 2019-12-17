// Voorbeeld van dynamic binding

#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    virtual void print(ostream& o) {
        o << soort() << endl;
    }
private:
    virtual string soort() const {
        return "Fruit";
    }
//  ...
};

class Appel: public Fruit {
private:
    virtual string soort() const {
        return "Appel";
    }
//  ...
};

class Peer: public Fruit {
private:
    virtual string soort() const {
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
    cin.get();
    return 0;
}

/* 
Uitvoer:

Fruit
Appel
Peer
*/
