import std;
using namespace std;

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
    virtual string naar_string() const = 0; // geef een stringrepresentatie
};

template<typename T> 
struct std::formatter<std::complex<T>>: public formatter<T> {
    auto format(const std::complex<T>& z, auto& context) const {
        context.advance_to(formatter<T>::format(z.real(), context));
        if (z.imag() >= 0)
            context.advance_to(format_to(context.out(), "+"));
        context.advance_to(formatter<T>::format(z.imag(), context));
        context.advance_to(format_to(context.out(), "j"));
        return context.out();
    }
};

template<>
struct std::formatter<Component>: public formatter<string> {
    auto format(const Component& c, auto& context) const {
        return formatter<string>::format(c.naar_string(), context);
    }
};

class R: public Component { // R = Weerstand
public:
    R(double r): r{r} {
    }
    complex<double> Z(double) const override {
        return r;
    }
    string naar_string() const override {
        return format("R({})", r);
    }
private:
    double r;
};

class L: public Component { // L = Spoel
public:
    L(double l): l{l} {
    }
    complex<double> Z(double f) const override {
        return complex<double> {0, 2 * numbers::pi * f * l};
    }
    string naar_string() const override {
        return format("L({})", l);
    }
private:
    double l;
};

class C: public Component { // C = Condensator
public:
    C(double c): c{c} {
    }
    complex<double> Z(double f) const override {
        return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
    }
    string naar_string() const override {
        return format("C({})", c);
    }
private:
    double c;
};

void print_impedance_table(const Component& c) {
    println("Impedantie tabel voor: {}\n", c);
    println("{:>7} | {}", "freq", "Z");
    println("{}", string(25, '-'));
    for (double freq(10); freq < 10E6; freq *= 10)
        println("{:>7.0f} | {:.3f}", freq, c.Z(freq));
    println();
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

   freq | Z
-------------------------
     10 | 100.000+0.000j
    100 | 100.000+0.000j
   1000 | 100.000+0.000j
  10000 | 100.000+0.000j
 100000 | 100.000+0.000j
1000000 | 100.000+0.000j

Impedantie tabel voor: C(1e-05)

   freq | Z
-------------------------
     10 | 0.000-1591.549j
    100 | 0.000-159.155j
   1000 | 0.000-15.915j
  10000 | 0.000-1.592j
 100000 | 0.000-0.159j
1000000 | 0.000-0.016j

Impedantie tabel voor: L(0.001)

   freq | Z
-------------------------
     10 | 0.000+0.063j
    100 | 0.000+0.628j
   1000 | 0.000+6.283j
  10000 | 0.000+62.832j
 100000 | 0.000+628.319j
1000000 | 0.000+6283.185j

*/
