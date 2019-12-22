#include <iostream>
using namespace std;

// define PROBLEM to show problem
//#define PROBLEM

class Whiskey_vat {
public:    
    void maak_vol() {
        cout << "Het vat is vol\n";
    }
    void maak_leeg() {
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

class Sint_bernard: public Hond {
public:
    Sint_bernard(): vat{new Whiskey_vat} {
        vat->maak_vol();
    }
    virtual ~Sint_bernard() {
        vat->maak_leeg();
        delete vat;
    }
    virtual void blaf() {
        cout << "WOEF WOEF\n";
    }
private:
    Whiskey_vat* vat;
};

int main() {
    Hond* boris{new Sint_bernard};
    boris->blaf();
    delete boris;
}


