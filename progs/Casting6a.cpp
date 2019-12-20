#include <iostream>
#include <typeinfo>
using namespace std;

class Hond {
public:
    virtual ~Hond() {
    }
    virtual void blaf() const {
        cout << "Blaf.\n";
    }
//  ...
};

class SintBernard: public Hond {
public:
    SintBernard(int w = 10): whisky{w} {
    }
    virtual void blaf() const {
        cout << "Woef!\n";
    }
    int geefDrank() {
        cout << "Geeft drank.\n";
        int w = whisky;
        whisky = 0;
        return w;
    };
//  ...
private:
    int whisky;
};

void geefHulp(Hond& hr) {
    hr.blaf();
    try {
        SintBernard& sbr{dynamic_cast<SintBernard&>(hr)};
        cout << sbr.geefDrank() << " liter.\n";
    } catch (bad_cast) {
    // Warning: catching polymorphic type ‘class std::bad_cast’ by value
        /* doe niets */
    }
}

int main() {
    SintBernard boris;
    geefHulp(boris);
    Hond fikkie;
    geefHulp(fikkie);
}

/* Output:
Woef!
Geeft drank.
10 liter.
Blaf.
*/
