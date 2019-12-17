#include <iostream>
using namespace std;

class UitleenbaarItem {
public:
    virtual string id() const = 0;
};

class DVD: public UitleenbaarItem {
public:
    virtual string id() const {
        // ...
    }
};

class Boek: public UitleenbaarItem {
public:
    virtual string id() const final {
        return ISBN;
    }
private:
    string ISBN;
};

class Reisgids: public Boek {
    virtual string id() const {
        // ...
    }
};

/*
In de bovenstaande derived class Reisgids is het niet toegestaan
om de functie id() te overridden omdat deze functie in de base
class Boek als final gemarkeerd is.

De Visual Studio 2012 C++ compiler geeft de volgende foutmeldingen:
'Boek::id': function declared as 'final' cannot be overridden by 'Reisgids::id'

De GCC 4.7.2 C++ compiler geeft de volgende foutmeldingen:
virtual function 'virtual std::string Reisgids::id() const' overriding final function 'virtual std::string Boek::id() const'
*/

int main() {
    DVD d;
    Boek b;
    Reisgids r;

    cin.get();
    return 0;
}
