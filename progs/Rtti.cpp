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
    void blaf() const override {
        println("Woef!");
    }
//  ...
};

void print_ras(Hond& h) {
    println("{}", typeid(h).name());
}

int main() {
    Sint_bernard boris;
    print_ras(boris);
    Hond fikkie;
    print_ras(fikkie);
}

/* Output:
12Sint_bernard
4Hond
*/
