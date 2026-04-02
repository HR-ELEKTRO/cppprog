import std;
using namespace std;

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
    virtual string naar_string() const = 0; // geef een stringrepresentatie
};

template<typename T> 
struct std::formatter<complex<T>>: public formatter<T> {
    auto format(const complex<T>& z, auto& context) const {
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
        if (c == 0.0)
            throw domain_error {"Capacity == 0"};
        if (f == 0.0)
            throw domain_error {"Frequency == 0"};
        return complex<double> {0, -1 / (2 * numbers::pi * f * c)};
    }
    string naar_string() const override {
        return format("C({})", c);
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
    string naar_string() const override {
        return format("({}+{})", c1.naar_string(), c2.naar_string());
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
        if (c1.Z(f) + c2.Z(f) == complex<double>(0, 0))
            throw domain_error {"Impedance of parallel circuit can not be calculated (due to divide by zero)"};
        return (c1.Z(f) * c2.Z(f)) / (c1.Z(f) + c2.Z(f));
    }
    string naar_string() const override {
        return format("({}//{})", c1.naar_string(), c2.naar_string());
    }
private:
    const Component& c1;
    const Component& c2;
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
    try {
        R r1 {1E2};
        C c1 {0}; // om te testen!
        L l1 {3E-2};
        S s1 {r1, c1};
        S s2 {r1, l1};
        P p {s1, s2};
        print_impedance_table(p);
    } catch (domain_error& e) {
        println("Exception: {}", e.what());
    }
    println();
    try {
        R r1 {10};
        R r2 {0};
        P p1 {r1, r1};
        P p2 {r2, r2}; // om te testen!
        print_impedance_table(p1);
        print_impedance_table(p2);
    } catch (domain_error& e) {
        println("Exception: {}", e.what());
    }
}

/* Uitvoer:

Impedantie tabel voor: ((R(100)+C(0))//(R(100)+L(0.03)))

   freq | Z
-------------------------
Exception: Capacity == 0

Impedantie tabel voor: (R(10)//R(10))

   freq | Z
-------------------------
     10 | 5.000+0.000j
    100 | 5.000+0.000j
   1000 | 5.000+0.000j
  10000 | 5.000+0.000j
 100000 | 5.000+0.000j
1000000 | 5.000+0.000j

Impedantie tabel voor: (R(0)//R(0))

   freq | Z
-------------------------
Exception: Impedance of parallel circuit can not be calculated (due to divide by zero)
*/