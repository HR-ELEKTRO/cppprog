import std;
using namespace std;

class Hond {
public:
    virtual ~Hond() = default; 
    virtual void blaf() const {
        println("Blaf.");
    }
//  ...
};

class Sint_bernard: public Hond {
public:
    Sint_bernard(int w = 10): whisky{w} {
    }
    void blaf() const override {
        println("Woef!");
    }
    int geef_drank() {
        println("Geeft drank.");
        int w {whisky};
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
        Sint_bernard& sbr {dynamic_cast<Sint_bernard&>(hr)};
        println("{} liter.", sbr.geef_drank());
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
