import std;
using namespace std;

class Hond {
public:
    explicit Hond(string_view n);
    ~Hond();
    void set_naam(string_view n);
    void blaf() const;
private:
    string naam;
};

Hond::Hond(string_view n): naam {n} {
    println("Hoera {} is geboren!", naam);
}

Hond::~Hond() {
    println("Helaas, {} is gestorven.", naam);
}

void Hond::set_naam(string_view n) {
    naam = n;
}

void Hond::blaf() const {
    println("Blaf blaf");
}

int main() {
    Hond h1 {"Fikkie"};
    h1.blaf();
    h1.set_naam("Kees");
    h1.blaf();
    const Hond h2 {"Leika"};
    h2.blaf();
//  h2.set_naam("Lex");
//  error: passing 'const Hond' as 'this' argument discards qualifiers
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
