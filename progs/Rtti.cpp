#include <iostream>
#include <typeinfo>
using namespace std;

class Hond {
public:
    virtual ~Hond() {
    }
    virtual void blaf() const {
        cout << "Blaf.\n";
    }
//  ...
};

class SintBernard: public Hond {
public:
    virtual void blaf() const {
        cout << "Woef!\n";
    }
//  ...
};

void printRas(Hond& hr) {
    cout << typeid(hr).name() << '\n';
}

int main() {
    SintBernard boris;
    printRas(boris);
    Hond h;
    printRas(h);
}

/* Output:
11SintBernard
4Hond
*/
