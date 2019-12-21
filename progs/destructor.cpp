#include <iostream>
using namespace std;

// define PROBLEM to show problem
//#define PROBLEM

class WhiskeyVat {
public:    
    void maakVol() {
        cout << "Het vat is vol\n";
    }
    void maakLeeg() {
        cout << "Het vat is leeg\n";
    }
};

class Hond {
public:
#ifndef PROBLEM
    virtual ~Hond() { } 
#else
// Warning: deleting object of abstract class type ‘Hond’ which has non-virtual destructor will cause undefined behavior
#endif
    virtual void blaf() = 0;
};

class SintBernard: public Hond {
public:
    SintBernard(): vat{new WhiskeyVat} {
        vat->maakVol();
    }
    virtual ~SintBernard() {
        vat->maakLeeg();
        delete vat;
    }
    virtual void blaf() {
        cout << "WOEF WOEF\n";
    }
private:
    WhiskeyVat* vat;
};

int main() {
    Hond* boris{new SintBernard};
    boris->blaf();
    delete boris;
}


