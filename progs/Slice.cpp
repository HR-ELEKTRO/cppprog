// Voorbeeld van slicing probleem

#include <iostream>
#include <string>
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
    cout << brojz.soort() << " " << brojz.naam() << " verdient " << brojz.salaris() << '\n';
    brojz.verhoog_salaris_met(10000);
    cout << brojz.soort() << " " << brojz.naam() << " verdient " << brojz.salaris() << '\n';

    Mens m {brojz}; // Waar blijft het salaris?
    cout << m.soort() << " " << m.naam() << " verdient " << m.salaris() << '\n';

//  Docent versd {m}; 
//  Error: no matching function for call to ‘Docent::Docent(<brace-enclosed initializer list>)

    Mens& mr {brojz};
    cout << mr.soort() << " " << mr.naam() << " verdient " << mr.salaris() << '\n';

    Mens* mp {&brojz};
    cout << mp->soort() << " " << mp->naam() << " verdient " << mp->salaris() << '\n';
}

/* Output:
docent Harry verdient 30000
docent Harry verdient 40000
mens Harry verdient 0
docent Harry verdient 40000
docent Harry verdient 40000
*/
