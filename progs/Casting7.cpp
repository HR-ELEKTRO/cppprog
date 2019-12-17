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
    if (dynamic_cast<const SintBernard*>(hp)!=0)
        cout << "Woef!" << endl;
    else if (dynamic_cast<const Tekkel*>(hp)!=0)
        cout << "Kef kef!" << endl;
    else
        cout << "Blaf." << endl;
}

int main() {
    Hond* borisPtr = new SintBernard;
    blaf(borisPtr);
    delete borisPtr;
    borisPtr = new Tekkel;
    blaf(borisPtr);
    delete borisPtr;
    cin.get();
    return 0;
}

/*
Output:

Woef!
Kef kef!
*/
