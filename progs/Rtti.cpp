#include <iostream>
#include <typeinfo>
using namespace std;

class Hond {
public:
    virtual ~Hond() {
    }
    virtual void blaf() const {
        cout << "Blaf." << endl;
    }
//  ...
};

class SintBernard: public Hond {
public:
    virtual void blaf() const {
        cout << "Woef!" << endl;
    }
//  ...
};

void printRas(Hond& hr) {
    cout << typeid(hr).name() << endl;
}

int main() {
    SintBernard boris;
    printRas(boris);
    Hond h;
    printRas(h);
    cin.get();
    return 0;
}

/*
// Output als het programma vertaald is met Microsoft Studio 2012
class SintBernard
class Hond

// Output als het programma vertaald is met GCC:
11SintBernard
4Hond
*/
