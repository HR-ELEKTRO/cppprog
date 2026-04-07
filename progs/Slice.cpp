// Voorbeeld van slicing probleem

import std;
using namespace std;

class Mens {
public:
    Mens(const string& n): name{n} {
    }
    string naam() const {
        return name;
    }
    virtual string soort() const {
        return "mens";
    }
    virtual unsigned int salaris() const {
        return 0;
    }
// ...
private:
    const string name;
};

class Docent: public Mens {
public:
    Docent(const string& n, unsigned short s): Mens{n}, sal{s} {
    }
    string soort() const override {
        return "docent";
    }
    unsigned int salaris() const override {
        return sal;
    }
    virtual void verhoog_salaris_met(unsigned short v) {
        sal += v;
    }
// ...
private:
    unsigned short sal;
};

int main() {
    Docent brojz {"Harry", 30000};
    println("{} {} verdient {}", brojz.soort(), brojz.naam(), brojz.salaris());
    brojz.verhoog_salaris_met(10000);
    println("{} {} verdient {}", brojz.soort(), brojz.naam(), brojz.salaris());

    Mens m {brojz}; // Waar blijft het salaris?
    println("{} {} verdient {}", m.soort(), m.naam(), m.salaris());

//  Docent versd {m}; 
//  Error: no matching function for call to ‘Docent::Docent(<brace-enclosed initializer list>)

    Mens& mr {brojz};
    println("{} {} verdient {}", mr.soort(), mr.naam(), mr.salaris());

    Mens* mp {&brojz};
    println("{} {} verdient {}", mp->soort(), mp->naam(), mp->salaris());
}

/* Output:
docent Harry verdient 30000
docent Harry verdient 40000
mens Harry verdient 0
docent Harry verdient 40000
docent Harry verdient 40000
*/
