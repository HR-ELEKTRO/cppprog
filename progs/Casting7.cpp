import std;
using namespace std;

// Deze code is NIET uitbreidbaar!
// ******* DON'T DO THIS IN YOUR CODE *******

class Hond {
public:
    virtual ~Hond() = default;
//  ...
};

class Sint_bernard: public Hond {
//  ...
};

class Tekkel: public Hond {
//  ...
};

//  Deze code is NIET uitbreidbaar!
//  ******* DON'T DO THIS IN YOUR CODE *******
//  blaf moet als virtual memberfunctie geimplementeerd worden!

void blaf(const Hond* hp) {
    if (dynamic_cast<const Sint_bernard*>(hp) != nullptr)
        println("Woef!");
    else if (dynamic_cast<const Tekkel*>(hp) != nullptr)
        println("Kef kef!");
    else
        println("Blaf.");
}

int main() {
    Sint_bernard boris;
    blaf(&boris);
    Tekkel harry;
    blaf(&harry);
}

/* Output:
Woef!
Kef kef!
*/
