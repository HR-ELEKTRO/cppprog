#include <iostream>
#include <string>
using namespace std;

class Hond {
public:
    explicit Hond(const string& n);
    ~Hond();
    void set_naam(const string& n);
    void blaf() const;
private:
    string naam;
};

Hond::Hond(const string& n): naam{n} {
    cout << "Hoera, " << naam << " is geboren!\n";
}

Hond::~Hond() {
    cout << "Helaas, " << naam << " is gestorven.\n";
}

void Hond::set_naam(const string& n) {
    naam = n;
}

void Hond::blaf() const {
    cout << "Blaf blaf\n";
}

int main() {
    Hond h1{"Fikkie"};
    h1.blaf();
    h1.set_naam("Kees");
    h1.blaf();
    const Hond h2{"Leika"};
    h2.blaf();
//  h2.set_naam("Lex");
//  Error: passing ‘const Hond’ as ‘this’ argument discards qualifiers
}

/* Uitvoer:
Hoera, Fikkie is geboren!
Blaf blaf
Blaf blaf
Hoera, Leika is geboren!
Blaf blaf
Helaas, Leika is gestorven.
Helaas, Kees is gestorven.
*/
