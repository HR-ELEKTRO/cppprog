// Voorbeeld van slicing probleem

#include <iostream>
#include <string>
using namespace std;

class Mens {
public:
    Mens(const string& n): name(n) {
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
    Docent(const string& n, unsigned short s): Mens(n), sal(s) {
    }
    virtual string soort() const {
        return "docent";
    }
    virtual unsigned int salaris() const {
        return sal;
    }
    virtual void verhoogSalarisMet(unsigned short v) {
        sal += v;
    }
// ...
private:
    unsigned short sal;
};

int main() {
    Docent bd("Harry", 30000);
    cout << bd.soort() << " " << bd.naam() << " verdient " << bd.salaris() << endl;
    bd.verhoogSalarisMet(10000);
    cout << bd.soort() << " " << bd.naam() << " verdient " << bd.salaris() << endl;

    Mens m(bd); // Waar blijft het salaris?
    cout << m.soort() << " " << m.naam() << " verdient " << m.salaris() << endl;

//  Docent jd(m); 
//  [C++ Error (Microsoft)]: 'Docent::Docent(const Docent &)' : cannot convert parameter 1 from 'Mens' to 'const Docent &' 
//                           Reason: cannot convert from 'Mens' to 'const Docent'
//  [C++ Error (GCC)]:       no matching function for call to 'Docent::Docent(Mens&)'
//                           note: candidates are:
//                           note: Docent::Docent(const string&, short unsigned int)
//                           note:   candidate expects 2 arguments, 1 provided
//                           note: Docent::Docent(const Docent&)
//                           note:   no known conversion for argument 1 from 'Mens' to 'const Docent&'

    Mens& mr(bd);
    cout << mr.soort() << " " << mr.naam() << " verdient " << mr.salaris() << endl;

    Mens* mp(&bd);
    cout << mp->soort() << " " << mp->naam() << " verdient " << mp->salaris() << endl;
//  ...
    cin.get();
    return 0;
}

/*
Output:
docent Harry verdient 30000
docent Harry verdient 40000
mens Harry verdient 0
docent Harry verdient 40000
docent Harry verdient 40000
*/
