#include <iostream>
using namespace std;

class Hond {
public:
    virtual ~Hond() = default;
    virtual void blaf() const {
        cout << "Blaf.\n";
    }
//  ...
};

class Sint_bernard: public Hond {
public:
    Sint_bernard(int w = 10): whisky{w} {
    }
    void blaf() const override {
        cout << "Woef!\n";
    }
    int geef_drank() {
        cout << "Geeft drank.\n";
        int w {whisky};
        whisky = 0;
        return w;
    };
//  ...
private:
    int whisky;
};

void geef_hulp(Hond* hp) {
    hp->blaf();
//  cout << hp->geef_drank() << " liter.\n";
//  Error: 'class Hond' has no member named 'geef_drank'
//  We kunnen een cast gebruiken maar dat geeft foutieve uitvoer als hp niet naar een Sint_bernard wijst.
    cout << static_cast<Sint_bernard*>(hp)->geef_drank() << " liter.\n";
}

int main() {
    Hond* boris_ptr {new Sint_bernard};
    geef_hulp(boris_ptr);
    delete boris_ptr;
    
    Hond* fikkie_ptr {new Hond};
    geef_hulp(fikkie_ptr);
    delete fikkie_ptr;
}

/* Output:
Woef!
Geeft drank.
10 liter.
Blaf.
Geeft drank.
-2144382840 liter.
*/
