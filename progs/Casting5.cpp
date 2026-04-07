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
    explicit Sint_bernard(int w = 10): whisky{w} {
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

void geef_hulp(Hond& h) {
    h.blaf();
    try {
        println("{} liter.", dynamic_cast<Sint_bernard&>(h).geef_drank());
    } catch (const bad_cast& e) {
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
