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
    void blaf() override {
        cout << "Kef kef\n";
    }
};

class Sint_bernard: public Hond {
public:
    void blaf() override {
        cout << "Woef woef\n";
    }
};

int main() {
    constexpr int s = 5;
//  Statische array: grootte is tijdens compilatie bekend.
    Tekkel a[s];
    cout << "5 tekkels zeggen:\n";
    for (int i {0}; i < s; ++i)
        a[i].blaf();

    int t;
    cout << "Hoeveel Tekkels wil je? ";
    cin >> t;
//  Statische array werkt niet als grootte tijdens compilatie onbekend is./*
///*
    Tekkel b[t]; 
//  Warning: ISO C++ forbids variable-size array `b'
//  Vreemd! Zou een fout moeten zijn!    
    cout << t << " tekkels zeggen:\n";
    for (int i {0}; i < t; ++i)
        b[i].blaf();
//*/
//  Dynamische array: grootte is tijdens compilatie niet bekend.
    Hond* c{new Tekkel[t]};
    cout << t << " tekkels zeggen:\n";
    for (int i {0}; i < t; ++i)
        c[i].blaf();
    delete[] c;
}
