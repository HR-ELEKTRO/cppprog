#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
// define PI (which is not included in std C++)
constexpr double PI = atan(1.0) * 4;

/*
Uitgangspunten:
-   een Component
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
*/

class Component {
public:
    virtual ~Component() = default;
    virtual complex<double> Z(double f) const = 0; // bereken de impedantie Z (een complex getal) bij de frequentie f
    virtual void print(ostream& out) const = 0; // print
};

ostream& operator<<(ostream& out, const Component& c) {
    c.print(out);
    return out;
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

void print_impedance_table(const Component& c) {
    cout << "Impedantie tabel voor: " << c << "\n\n";
    cout << setw(10) << "freq" << setw(20) << "Z\n";
    for (double freq(10); freq < 10E6; freq *= 10)
        cout << setw(10) << freq << setw(20) << c.Z(freq) << '\n';
    cout << '\n';
}

int main() {
    R r {1E2};
    print_impedance_table(r);
    C c {1E-5};
    print_impedance_table(c);
    L l {1E-3};
    print_impedance_table(l);
}

/* Uitvoer:
Impedantie tabel voor: R(100)

      freq                   Z
        10             (100,0)
       100             (100,0)
      1000             (100,0)
     10000             (100,0)
    100000             (100,0)
    1e+006             (100,0)


Impedantie tabel voor: C(1e-005)

      freq                   Z
        10        (0,-1591.55)
       100        (0,-159.155)
      1000        (0,-15.9155)
     10000        (0,-1.59155)
    100000       (0,-0.159155)
    1e+006      (0,-0.0159155)


Impedantie tabel voor: L(0.001)

      freq                   Z
        10       (0,0.0628319)
       100        (0,0.628319)
      1000         (0,6.28319)
     10000         (0,62.8319)
    100000         (0,628.319)
    1e+006         (0,6283.19)
*/
