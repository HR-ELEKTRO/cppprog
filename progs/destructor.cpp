#include <iostream>
using namespace std;

// define PROBLEM to show problem
//#define PROBLEM

class WhiskeyVat {
public:    
    void maakVol() {
        cout << "Het vat is vol" << endl;
    }
    void maakLeeg() {
        cout << "Het vat is leeg" << endl;
    }
};

class Hond {
public:
#ifndef PROBLEM
    virtual ~Hond() { } 
#endif
    virtual void blaf() = 0;
};

class SintBernard: public Hond {
public:
    SintBernard(): vat(new WhiskeyVat) {
        vat->maakVol();
    }
    virtual ~SintBernard() {
        vat->maakLeeg();
        delete vat;
    }
    virtual void blaf() {
        cout << "WOEF WOEF" << endl;
    }
private:
    WhiskeyVat* vat;
};

int main() {
    Hond* boris = new SintBernard;
    boris->blaf();
    delete boris;
    cin.get();
    return 0;
}


