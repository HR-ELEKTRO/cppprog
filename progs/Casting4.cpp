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

void geef_hulp(Hond* hp) {
    hp->blaf();
//  println("{}", hp->geef_drank());
//  Error: 'class Hond' has no member named 'geef_drank'
//  We kunnen een cast gebruiken maar dat geeft foutieve uitvoer als hp niet naar een Sint_bernard wijst.
    println("{} liter.", static_cast<Sint_bernard*>(hp)->geef_drank());
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
1714 liter.
*/
