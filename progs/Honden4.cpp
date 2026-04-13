import std;
using namespace std;

class Hond {
public:
    explicit Hond(string_view n);
    virtual ~Hond();
    void set_naam(string_view n);
    virtual void blaf() const;
private:
    string naam;
};

class Teckel: public Hond {
public:
    explicit Teckel(string_view n);
    ~Teckel() override;
    void blaft() const override; // OOPS foutje
//  foutje wordt door de compiler gemeld:
//  error: 'void Teckel::blaft() const' marked 'override', but does not override
};

Hond::Hond(string_view n): naam {n} {
    println("Hoera, {} is geboren!", naam);
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

Teckel::Teckel(string_view n): Hond {n} {
    println("Er is een Teckel geboren!");
}

Teckel::~Teckel() {
    println("Er is een Teckel gestorven.");
}

void Teckel::blaft() const {
    println("Kef kef");
}

int main() {
    Teckel h1 {"Biefie"};
    h1.blaf();
}
