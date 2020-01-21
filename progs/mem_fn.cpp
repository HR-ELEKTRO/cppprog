#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Hond {
public:
    virtual ~Hond() = default;
    virtual void blaf() const = 0;
};

class Tekkel: public Hond {
public:
    void blaf() const override {
        cout << "Kef kef ";
    }
};

class St_bernard: public Hond {
public:
    void blaf() const override {
        cout << "Woef woef ";
    }
};

void fblaf(const Hond* p) {
    p->blaf();
}

int main() {
    list<Hond*> kennel{new Tekkel, new St_bernard, new Tekkel};
    for_each(kennel.cbegin(), kennel.cend(), mem_fn(&Hond::blaf));
    cout << '\n';

//  alternatief met lambda functie
    for_each(kennel.cbegin(), kennel.cend(), [](const auto p) {
        p->blaf();
    });
    cout << '\n';

//  alternatief met functie
    for_each(kennel.cbegin(), kennel.cend(), fblaf);
    cout << '\n';
    
//  alternatief met range-based for
    for (const auto p: kennel) {
        p->blaf();
    }
    cout << '\n';

    for (auto p: kennel) {
        delete p;
    }
}
