import std;
using namespace std;

class Hond {
public:
    virtual ~Hond() = default;
    virtual void blaf() const = 0;
};

class Tekkel: public Hond {
public:
    void blaf() const override {
        print("Kef kef ");
    }
};

class St_bernard: public Hond {
public:
    void blaf() const override {
        print("Woef woef ");
    }
};

void fblaf(const shared_ptr<Hond>& p) {
    p->blaf();
}

int main() {
    list<shared_ptr<Hond>> kennel {make_shared<Tekkel>(), make_shared<St_bernard>(), make_shared<Tekkel>()};
    ranges::for_each(kennel, mem_fn(&Hond::blaf));
    println();

//  alternatief met lambda functie
    ranges::for_each(kennel, [](const auto p) {
        p->blaf();
    });
    println();

//  alternatief met functie
    ranges::for_each(kennel, fblaf);
    println();
    
//  alternatief met range-based for
    for (const auto& p: kennel) {
        p->blaf();
    }
    println();
}
