#include <iostream>
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

void geefHulp(Hond* hp) {
    hp->blaf();
    SintBernard* sbp(dynamic_cast<SintBernard*>(hp));
    if (sbp != nullptr)
        cout << sbp->geefDrank() << " liter.\n";
}

int main() {
    Hond* borisPtr{new SintBernard};
    geefHulp(borisPtr);
    delete borisPtr;
    
    Hond* fikkiePtr{new Hond};
    geefHulp(fikkiePtr);
    delete fikkiePtr;

//  SintBernard* sbp{new Hond};
//  Error: invalid conversion from 'Hond*' to 'SintBernard*'
}

/* Output:
Woef!
Geeft drank.
10 liter.
Blaf.
*/
