#include <iostream>
using namespace std;

// Deze code is NIET uitbreidbaar!
// ******* DON'T DO THIS IN YOUR CODE *******

class Hond {
public:
    virtual ~Hond();
//  ...
};

Hond::~Hond() {
}

class SintBernard: public Hond {
//  ...
};

class Tekkel: public Hond {
//  ...
};

//  Deze code is NIET uitbreidbaar!
//  ******* DON'T DO THIS IN YOUR CODE *******
//  blaf moet als virtual memberfunctie geimplementeerd worden!

void blaf(const Hond* hp) {
    if (dynamic_cast<const SintBernard*>(hp) != nullptr)
        cout << "Woef!\n";
    else if (dynamic_cast<const Tekkel*>(hp) != nullptr)
        cout << "Kef kef!\n";
    else
        cout << "Blaf.\n";
}

int main() {
    Hond* borisPtr{new SintBernard};
    blaf(borisPtr);
    delete borisPtr;
    borisPtr = new Tekkel;
    blaf(borisPtr);
    delete borisPtr;
}

/* Output:
Woef!
Kef kef!
*/
