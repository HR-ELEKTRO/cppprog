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
        int w(whisky);
        whisky = 0;
        return w;
    };
//  ...
private:
    int whisky;
};

void geefHulp(Hond* hp) {
    hp->blaf();
//  cout << hp->geefDrank() << " liter." << endl;
//  [C++ Error (Microsoft)] 'geefDrank' : is not a member of 'Hond'
//  [C++ Error (GCC)]       'class Hond' has no member named 'geefDrank'
//  We kunnen een cast gebruiken maar dat geeft foutieve uitvoer als hp niet naar een SintBernard wijst.
    cout << static_cast<SintBernard*>(hp)->geefDrank() << " liter." << endl;
}

int main() {
    Hond* borisPtr = new SintBernard;
    geefHulp(borisPtr);
    delete borisPtr;
    
    Hond* fikkiePtr = new Hond;
    geefHulp(fikkiePtr);
    delete fikkiePtr;

    cin.get();
    return 0;
}

/*
Output:

Woef!
Geeft drank.
10 liter.
Blaf.
Geeft drank.
-33686019 liter.
*/
