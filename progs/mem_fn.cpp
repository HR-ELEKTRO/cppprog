#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

class Hond {
public:
    virtual ~Hond() = default;
    virtual void blaf() const = 0;
};

class Tekkel: public Hond {
public:
    virtual void blaf() const override {
        cout << "Kef kef ";
    }
};

class St_bernard: public Hond {
public:
    virtual void blaf() const override {
        cout << "Woef woef ";
    }
};

void fblaf(const Hond* p) {
    p->blaf();
}

function pblaf{
    [](const Hond* p){
        p->blaf();
    }
};

int main() {
    list<Hond*> kennel{new Tekkel, new St_bernard, new Tekkel};
    for_each(kennel.cbegin(), kennel.cend(), mem_fn(&Hond::blaf));
    cout << '\n';

//  alternatief met lambda functie
    for_each(kennel.cbegin(), kennel.cend(), [](const Hond* p) {
        p->blaf();
    });
    cout << '\n';

//  alternatief met functie
    for_each(kennel.cbegin(), kennel.cend(), fblaf);
    cout << '\n';
    
//  alternatief met function object
    for_each(kennel.cbegin(), kennel.cend(), pblaf);
    cout << '\n';

//  alternatief met range-based for
    for (const auto p: kennel) {
        p->blaf();
    }
    cout << '\n';
}
