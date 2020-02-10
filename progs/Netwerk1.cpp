#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI = atan(1.0) * 4;

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
    complex<double> Z(double) const override {
        return r;
    }
    void print(ostream& o) const override {
        o << "R(" << r << ")";
    }
private:
    double r;
};

class L: public Component { // L = Spoel
public:
    L(double l): l{l} {
    }
    complex<double> Z(double f) const override {
        return complex<double> {0, 2 * PI * f * l};
    }
    void print(ostream& o) const override {
        o << "L(" << l << ")";
    }
private:
    double l;
};

class C: public Component { // C = Condensator
public:
    C(double c): c{c} {
    }
    complex<double> Z(double f) const override {
        return complex<double> {0, -1 / (2 * PI * f * c)};
    }
    void print(ostream& o) const override {
        o << "C(" << c << ")";
    }
private:
    double c;
};

class S: public Component { // S = Serie schakeling van twee componenten
public:
    S(const Component& c1, const Component& c2): c1{c1}, c2{c2} {
    }
    complex<double> Z(double f) const override {
        return c1.Z(f) + c2.Z(f);
    }
    void print(ostream& o) const override {
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
    complex<double> Z(double f) const override {
        return (c1.Z(f) * c2.Z(f)) / (c1.Z(f) + c2.Z(f));
    }
    void print(ostream& o) const override {
        o << "(" << c1 << "//" << c2 << ")";
    }
private:
    const Component& c1;
    const Component& c2;
};

void print_impedance_table(const Component& c) {
    cout << "Impedantie tabel voor: " << c << "\n\n";
    cout << setw(10) << "freq" << setw(20) << "Z\n";
    for (double freq(10); freq < 10E6; freq *= 10)
        cout << setw(10) << freq << setw(20) << c.Z(freq) << '\n';
    cout << '\n';
}

int main() {
    R r1 {1E2};
    C c1 {1E-6};
    L l1 {3E-2};
    S s1 {r1, c1};
    S s2 {r1, l1};
    P p {s1, s2};
    print_impedance_table(p);
}

/* Uitvoer:

Impedantie tabel voor: ((R(100)+C(1e-006))//(R(100)+L(0.03)))

      freq                   Z
        10   (100.016,1.25659)
       100   (101.591,12.5146)
      1000  (197.893,-14.3612)
     10000  (101.132,-10.5795)
    100000    (100.011,-1.061)
    1e+006     (100,-0.106103)
*/