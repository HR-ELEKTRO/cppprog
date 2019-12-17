#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    Hond(const string& n);
    ~Hond();
    void setNaam(const string& n);
    void blaf() const;
private:
    string naam;
};

Hond::Hond(const string& n): naam(n) {
    cout << "Hoera, " << naam << " is geboren!" << endl;
}

Hond::~Hond() {
    cout << "Helaas, " << naam << " is gestorven." << endl;
    cin.get();
}

void Hond::setNaam(const string& n) {
    naam = n;
}

void Hond::blaf() const {
    cout << "Blaf blaf" << endl;
}

int main() {
    Hond h1("Fikkie");
    h1.blaf();
    h1.setNaam("Kees");
    const Hond h2("Leika");
    h2.blaf();
//  h2.setNaam("Lex");
//  [C++ Error (Microsoft)] 'Hond::setNaam' : cannot convert 'this' pointer from 'const Hond' to 'Hond &'
//  [C++ Error (GCC)]       no matching function for call to `Hond::setNaam(const char[4]) const'
    cin.get();
    return 0;
}

/*
Uitvoer:
Hoera, Fikkie is geboren!
Blaf blaf
Hoera, Leika is geboren!
Blaf blaf
<enter>
Helaas, Leika is gestorven.
<enter>
Helaas, Kees is gestorven.
<enter>
*/
