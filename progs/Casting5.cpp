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

void geef_hulp(Hond* hp) {
    hp->blaf();
    Sint_bernard* sbp(dynamic_cast<Sint_bernard*>(hp));
    if (sbp != nullptr)
        cout << sbp->geef_drank() << " liter.\n";
}

int main() {
    Hond* boris_ptr{new Sint_bernard};
    geef_hulp(boris_ptr);
    delete boris_ptr;
    
    Hond* fikkie_ptr{new Hond};
    geef_hulp(fikkie_ptr);
    delete fikkie_ptr;

//  Sint_bernard* sbp{new Hond};
//  Error: invalid conversion from 'Hond*' to 'Sint_bernard*'
}

/* Output:
Woef!
Geeft drank.
10 liter.
Blaf.
*/
