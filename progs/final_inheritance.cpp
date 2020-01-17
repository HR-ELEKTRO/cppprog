#include <iostream>
using namespace std;

class Uitleenbaar_item {
public:
    virtual string id() const = 0;
};

class DVD final: public Uitleenbaar_item {
public:
    string id() const override {
        string s;
        // ...
        return s;
    }
};

class Disney_DVD: public DVD {
};

/*
Het is niet toegestaan om van de class DVD te overerven

De GCC C++ compiler geeft de volgende foutmelding:
cannot derive from 'final' base 'DVD' in derived type 'disney_DVD'
*/

int main() {
    DVD d;
    Disney_DVD dd;
}
