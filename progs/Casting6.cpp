#include <iostream>
#include <typeinfo>
using namespace std;

class Hond {
public:
    virtual ~Hond() {
    }
    virtual void blaf() const {
        cout << "Blaf." << endl;
    }
//  ...
};

class SintBernard: public Hond {
public:
    SintBernard(int w = 10): whisky(w) {
    }
    virtual void blaf() const {
        cout << "Woef!" << endl;
    }
    int geefDrank() {
        cout << "Geeft drank." << endl;
        int i(whisky);
        whisky = 0;
        return i;
    };
//  ...
private:
    int whisky;
};

void geefHulp(Hond& hr) {
    hr.blaf();
    try {
        SintBernard& sbr(dynamic_cast<SintBernard&>(hr));
        cout << sbr.geefDrank() << " liter." << endl;
    } catch (bad_cast) {
        /* doe niets */
    }
}

int main() {
    SintBernard boris;
    geefHulp(boris);
    Hond fikkie;
    geefHulp(fikkie);
    cin.get();
    return 0;
}

/*
Output:

Woef!
Geeft drank.
10 liter.
Blaf.
*/
