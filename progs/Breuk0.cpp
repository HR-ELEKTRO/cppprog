// Werken met breuken in C++ ... een eerste stap naar een ADT

#include <iostream>
#include <cassert>
using namespace std;

class Breuk {                  // Op een object van de class Breuk
public:                        // kun je de volgende bewerkingen uitvoeren:
    void leesin();             //    inlezen vanuit het toetsenbord.
    void drukaf() const;       //    afdrukken op het scherm.
    void plus(const Breuk& b); //    een Breuk erbij optellen.
private:                       // Een object van de class Breuk heeft privé:
    int boven;                 //    een teller,
    int onder;                 //    een noemer en
    void normaliseer();        //    een functie normaliseer.
};

void Breuk::leesin() {
    cout << "Type een breuk (2 getallen gescheiden door een spatie): ";
    cin >> boven >> onder;
    assert(onder != 0);
    normaliseer();
}

void Breuk::drukaf() const {
    cout << boven << "/" << onder;
}

void Breuk::plus(const Breuk& b) {
    boven = boven * b.onder + onder * b.boven;
    onder *= b.onder;
    normaliseer();
}

unsigned int ggd(unsigned int n, unsigned int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    while (m != n)
        if (n > m) n -= m;
        else m -= n;
    return n;
}

void Breuk::normaliseer() {
    if (onder < 0) {
        onder =- onder;
        boven =- boven;
    }
    int d = ggd(boven < 0 ? -boven : boven, onder);
    boven /= d;
    onder /= d;
}

int main() {
    Breuk a, b; // definieer de objecten a en b van de class Breuk
    a.leesin(); // lees a in
    b.leesin(); // lees b in
    a.drukaf();
    cout << " + ";
    b.drukaf();
    cout << " = ";
    a.plus(b);  // tel b bij a op
    a.drukaf(); // druk a af
    cout << '\n';
}