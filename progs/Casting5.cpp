#include <iostream>
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

void geefHulp(Hond* hp) {
    hp->blaf();
    SintBernard* sbp(dynamic_cast<SintBernard*>(hp));
    if (sbp)
        cout << sbp->geefDrank() << " liter." << endl;
}

int main() {
    Hond* borisPtr = new SintBernard;
    geefHulp(borisPtr);
    delete borisPtr;
    Hond* fikkiePtr = new Hond;
    geefHulp(fikkiePtr);
    delete fikkiePtr;

//  SintBernard* sbp = new Hond;
//  [C++ Error (Microsoft)] 'initializing' : cannot convert from 'Hond *' to 'SintBernard *'
//  [C++ Error (GCC)]       invalid conversion from 'Hond*' to 'SintBernard*'

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
