#include <iostream>
#include <typeinfo>
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
    void blaf() const override {
        cout << "Woef!\n";
    }
//  ...
};

void print_ras(Hond& hr) {
    cout << typeid(hr).name() << '\n';
}

int main() {
    Sint_bernard boris;
    print_ras(boris);
    Hond h;
    print_ras(h);
}

/* Output:
12Sint_bernard
4Hond
*/
