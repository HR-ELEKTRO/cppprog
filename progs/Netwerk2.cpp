#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;
// define PI (which is not included in std C++)
const double PI = atan(1.0) * 4;

/*
Uitgangspunten:
-    een Component
    -   is een abstracte base class
    -   heeft een impedantie Z die afhankelijk is van de frequentie f
    -   kan geprint worden
-   een R (weerstand)
    -   is een soort Component
    -   heeft een weerstandswaarde (r) uitgedrukt in Ohm
    -   Z(f) = r + j * 0
-   een L (spoel)
    -   is een soort Component
    -   heeft een zelfinductie (l) uitgedrukt in Henry
    -   Z(f) = 0 + j * 2 * pi * f * l
-   een C (condensator)
    -   is een soort Component
    -   heeft een capaciteit (c) uitgedrukt in Farad
    -   Z(f) = 0 - j / (2 * pi * f * c)
-   een S (Serie schakeling)
    -   is een soort Component
    -   is een samenstelling van twee Componenten
    -   Z(f) = Z1(f) + Z2(f)
-   een P (Parallel schakeling)
    -   is een soort Component
    -   is een samenstelling van twee Componenten
    -   Z(f) = 1 / (1 / Z1(f) + 1 / Z2(f))
    -        = (Z1(f) * Z2(f)) / (Z1(f) + Z2(f));
*/

class Component {
public:
    virtual ~Component() = default;
    virtual complex<double> Z(double f) const = 0; // bereken de impedantie Z (een complex getal) bij de frequentie f
    virtual void print(ostream& o) const = 0; // print
};

ostream& operator<<(ostream& o, const Component& c) {
    c.print(o);
    return o;
}

class R: public Component { // R = Weerstand
public:
    R(double r): r{r} {
    }
    virtual complex<double> Z(double) const {
        return r;
    }
    virtual void print(ostream& o) const {
        o << "R(" << r << ")";
    }
private:
    double r;
};

class L: public Component { // L = Spoel
public:
    L(double l): l{l} {
    }
    virtual complex<double> Z(double f) const {
        return complex<double>(0, 2 * PI * f * l);
    }
    virtual void print(ostream& o) const {
        o << "L(" << l << ")";
    }
private:
    double l;
};

class C: public Component { // C = Condensator
public:
    C(double c): c{c} {
    }
    virtual complex<double> Z(double f) const {
        if (c == 0.0)
            throw domain_error("Capacity == 0");
        if (f == 0.0)
            throw domain_error("Frequency == 0");
        return complex<double>(0, -1 / (2 * PI * f * c));
    }
    virtual void print(ostream& o) const {
        o << "C(" << c << ")";
    }
private:
    double c;
};

class S: public Component { // S = Serie schakeling van twee componenten
public:
    S(const Component& c1, const Component& c2): c1{c1}, c2{c2} {
    }
    virtual complex<double> Z(double f) const {
        return c1.Z(f) + c2.Z(f);
    }
    virtual void print(ostream& o) const {
        o << "(" << c1 << "+" << c2 << ")";
    }
private:
    const Component& c1;
    const Component& c2;
};

class P: public Component { // P = Parallel schakeling van twee componenten
public:
    P(const Component& c1, const Component& c2): c1{c1}, c2{c2} {
    }
    virtual complex<double> Z(double f) const {
        if (c1.Z(f) + c2.Z(f) == complex<double>(0, 0))
            throw domain_error("Impedance of parallel circuit can not be calculated (due to divide by zero)");
        return (c1.Z(f) * c2.Z(f)) / (c1.Z(f) + c2.Z(f));
    }
    virtual void print(ostream& o) const {
        o << "(" << c1 << "//" << c2 << ")";
    }
private:
    const Component& c1;
    const Component& c2;
};

void printImpedanceTable(const Component& c) {
    cout << "Impedantie tabel voor: " << c << "\n\n";
    cout << setw(10) << "freq" << setw(20) << "Z\n";
    for (double freq(10); freq < 10E6; freq *= 10)
        cout << setw(10) << freq << setw(20) << c.Z(freq) << '\n';
    cout << '\n';
}

int main() {
    try {
        R r1{1E2};
        C c1{0}; // om te testen!
        L l1{3E-2};
        S s1{r1, c1};
        S s2{r1, l1};
        P p{s1, s2};
        printImpedanceTable(p);
    } catch (domain_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    cout << endl;
    try {
        R r1{10};
        R r2{0};
        P p1{r1, r1};
        P p2{r2, r2}; // om te testen!
        printImpedanceTable(p1);
        printImpedanceTable(p2);
    } catch (domain_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

/* Uitvoer:

Impedantie tabel voor: ((R(100)+C(0))//(R(100)+L(0.03)))

      freq                   Z
Exception: Capacity == 0

Impedantie tabel voor: (R(10)//R(10))

      freq                   Z
        10               (5,0)
       100               (5,0)
      1000               (5,0)
     10000               (5,0)
    100000               (5,0)
    1e+006               (5,0)

Impedantie tabel voor: (R(0)//R(0))

      freq                   Z
Exception: Impedance of parallel circuit can not be calculated (due to divide by zero)
*/