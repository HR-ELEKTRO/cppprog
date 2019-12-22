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

class Sint_bernard: public Hond {
public:
    Sint_bernard(int w = 10): whisky{w} {
    }
    virtual void blaf() const {
        cout << "Woef!\n";
    }
    int geef_drank() {
        cout << "Geeft drank.\n";
        int w = whisky;
        whisky = 0;
        return w;
    };
//  ...
private:
    int whisky;
};

void geef_hulp(Hond& hr) {
    hr.blaf();
    try {
        Sint_bernard& sbr{dynamic_cast<Sint_bernard&>(hr)};
        cout << sbr.geef_drank() << " liter.\n";
    } catch (const bad_cast&) {
        /* doe niets */
    }
}

int main() {
    Sint_bernard boris;
    geef_hulp(boris);
    Hond fikkie;
    geef_hulp(fikkie);
}

/* Output:
Woef!
Geeft drank.
10 liter.
Blaf.
*/
