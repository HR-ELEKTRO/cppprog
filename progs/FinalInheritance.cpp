#include <iostream>
using namespace std;

class UitleenbaarItem {
public:
    virtual string id() const = 0;
};

class DVD final: public UitleenbaarItem {
public:
    virtual string id() const {
        string s;
        // ...
        return s;
    }
};

class DisneyDVD: public DVD {
};

/*
Het is niet toegestaan om van de class DVD te overerven

De GCC C++ compiler geeft de volgende foutmelding:
cannot derive from 'final' base 'DVD' in derived type 'DisneyDVD'
*/

int main() {
    DVD d;
    DisneyDVD dd;
}
