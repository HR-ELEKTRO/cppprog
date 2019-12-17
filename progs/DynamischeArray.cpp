#include <iostream>
using namespace std;

class Hond {
public:
    virtual ~Hond();
    virtual void blaf() = 0;
};

Hond::~Hond() {
}

class Tekkel: public Hond {
public:
    virtual void blaf() {
        cout << "Kef kef" << endl;
    }
};

class SintBernard: public Hond {
public:
    virtual void blaf() {
        cout << "Woef woef" << endl;
    }
};

int main() {
    const int s = 5;
//  Statische array: grootte is tijdens compilatie bekend.
    Tekkel a[s];
    for (int i = 0; i < s; ++i)
        a[i].blaf();

    int t;
    cout << "Hoeveel Tekkels wil je? ";
    cin >> t;
//  Statische array werkt niet als grootte tijdens compilatie onbekend is./*
/*
    Tekkel b[t]; 
//  Error Microsoft: expected constant expression
//  Error GCC:       ISO C++ forbids variable-size array `b'
    for (int i = 0; i < t; ++i)
        b[i].blaf();
*/
//  Dynamische array: grootte is tijdens compilatie niet bekend.
    Hond* c = new Tekkel[t];
    for (int i = 0; i < t; ++i)
        c[i].blaf();
    delete[] c;

    cin.get(); 
    cin.get();
    return 0;
}
