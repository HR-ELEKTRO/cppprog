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

class StBernard: public Hond {
public:
    virtual void blaf() const override {
        cout << "Woef woef ";
    }
};

int main() {
    list<Hond*> kennel = {new Tekkel, new StBernard, new Tekkel};
    for_each(kennel.cbegin(), kennel.cend(), mem_fn(&Hond::blaf));
    cout << endl;

//  alternatief met lambda functie
    for_each(kennel.cbegin(), kennel.cend(), [](const Hond* p) {
        p->blaf();
    });
    cout << endl;

//  alternatief met range-based for
    for (const auto p: kennel) {
        p->blaf();
    }
    cout << endl;

    cin.get();
    return 0;
}
