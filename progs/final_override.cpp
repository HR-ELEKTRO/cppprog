import std;
using namespace std;

class Uitleenbaar_item {
public:
    virtual string id() const = 0;
};

class DVD: public Uitleenbaar_item {
public:
    string id() const override {
        return barcode;
    }
private:
    string barcode;
};

class Boek: public Uitleenbaar_item {
public:
    string id() const final {
        return ISBN;
    }
private:
    string ISBN;
};

class Reisgids: public Boek {
    string id() const override {
        return bestemming;
    }
private:
    string bestemming;
};

/*
In de bovenstaande derived class Reisgids is het niet toegestaan
om de functie id() te overridden omdat deze functie in de base
class Boek als final gemarkeerd is.

De GCC C++ compiler geeft de volgende foutmelding:
 virtual function ‘virtual std::string Reisgids::id() const’ overriding final function
*/

int main() {
    DVD d;
    Boek b;
    Reisgids r;
}
