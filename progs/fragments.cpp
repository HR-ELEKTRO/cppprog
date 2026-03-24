import std;
#include <cassert>
using namespace std;

//>abs_not_overloaded
int absolute_waarde_int(int i) {
    if (i < 0) return -i; else return i;
}
double absolute_waarde_double(double f) {
    if (f < 0) return -f; else return f;
}
//<abs_not_overloaded

//>abs_overloaded
int absolute_waarde(int i) {
    if (i < 0) return -i; else return i;
}
double absolute_waarde(double f) {
    if (f < 0) return -f; else return f;
}
//<abs_overloaded

//>def_par
void print_int(int i, int talstelsel = 10);
//<def_par

void print_int(int i, int talstelsel) {
}

//>struct_Tijdsduur
struct Tijdsduur { // Een Tijdsduur bestaat uit:
    int uur;       //     een aantal uren en
    int min;       //     een aantal minuten.
};
//<struct_Tijdsduur

class Breuk {
public:
    Breuk();
    Breuk(int t);
    Breuk(int t, int n);
    Breuk& operator+=(const Breuk& rechts);
    Breuk& operator++();         // prefix
    const Breuk operator++(int); // postfix
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
friend bool operator==(const Breuk& links, const Breuk& rechts);
};

istream& operator>>(istream& in, Breuk& b);
const Breuk operator+(const Breuk& links, const Breuk& rechts);

int ggd(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != n)
        if (n > m) n -= m;
        else m -= n;
    return n;
}

Breuk::Breuk(): boven{0}, onder{1} {
}

Breuk::Breuk(int t): boven{t}, onder{1} {
}

Breuk::Breuk(int t, int n): boven{t}, onder{n} {
    normaliseer();
}

Breuk& Breuk::operator+=(const Breuk& rechts) {
    boven = boven * rechts.onder + onder * rechts.boven;
    onder *= rechts.onder;
    normaliseer();
    return *this;
}

Breuk& Breuk::operator++() {
    boven += onder;
    return *this;
}

const Breuk Breuk::operator++(int) {
    Breuk b(*this);
    ++(*this);
    return b;
}

void Breuk::normaliseer() {
    assert(onder != 0);
    if (onder < 0) {
        onder = -onder;
        boven = -boven;
    }
    int d = ggd(boven, onder);
    boven /= d;
    onder /= d;
}

const Breuk operator+(const Breuk& links, const Breuk& rechts) {
    Breuk copy_links{links};
    copy_links += rechts;
    return copy_links;
}

ostream& operator<<(ostream& out, const Breuk& b) {
    return out << b.boven << '/' << b.onder;
}

istream& operator>>(istream& in, Breuk& b) {
    int teller;
    if (in >> teller)
        if (in.peek() == '/') {
            in.get();
            int noemer;
            if (in >> noemer) b = Breuk(teller, noemer);
            else b = Breuk{teller};
        }
        else b = Breuk{teller};
    else b = Breuk{};
    return in;
}

template<>
struct std::formatter<Breuk>: public formatter<string> {
    auto format(const Breuk& breuk, format_context& context) const {
        ostringstream ss;
        ss << breuk;
        return formatter<string>::format(ss.str(), context);
    }
};

bool operator==(const Breuk& links, const Breuk& rechts) {
    return links.boven == rechts.boven && links.onder == rechts.onder;
}

//>Breuk3_main
int main() {
    Breuk b1, b2;              // definiëren van variabelen
    print("Geef Breuk: ");
    cin >> b1;                 // inlezen met >>
    print("Geef nog een Breuk: ");
    cin >> b2;                 // inlezen met >>
    println("{} + {} = {}", b1, b2, b1 + b2); // afdrukken met println en optellen met +
    Breuk b3 {18, -9};         // definiëren en initialiseren
    if (b1 != b3) {            // vergelijken met !=
        ++b3;                  // verhogen met ++
    }
    println("{}", b3);         // afdrukken met println
    b3 += 5;                   // verhogen met +=
    println("{}", b3);         // afdrukken met println
    if (-2 == b3) {            // vergelijken met een int
        println("OK");
    } 
//<Breuk3_main
//>Breuk3_main2
    else {
        println("Error.");
    }
}
//<Breuk3_main2

void dummy() {
{
//>som_in_C
    int rij[] {12, 2, 17, 32, 1, 18};
    size_t aantal {sizeof rij / sizeof rij[0]};
    int som {0};
    for (size_t i {0}; i < aantal; i++) {
        som += rij[i];
    }
//<som_in_C
}
{
//>som_in_Cpp_zonder_auto
    int rij[] {12, 2, 17, 32, 1, 18};
    int som {0};
    for (int element: rij) {
        som += element;
    }
//<som_in_Cpp_zonder_auto
}
{
//>use_abs_overloaded
    double d;
    cin >> d; // lees d in
    println("{}", absolute_waarde(d)); // druk de absolute waarde van d af
//<use_abs_overloaded
}
{
    
//>use_def_par
    print_int(12, 2);  // uitvoer: 1100
    print_int(12);     // uitvoer: 12
    print_int(12, 10); // uitvoer: 12
    print_int(12, 7);  // uitvoer: 15
//<use_def_par
}
{
//>use_struct_C
    struct Tijdsduur td1;
//<use_struct_C
}
{
//>struct_typedef
typedef struct Tijdsduur Tijdsduur_t;
//<struct_typedef
//>use_struct_typedef
    Tijdsduur_t td2;
//<use_struct_typedef
}
{
//>use_struct_Cpp
    Tijdsduur td3;
//<use_struct_Cpp
}
{
    int a, b = 1;
    a = ++++b;
    println("a = {}", a);
    // a = b++++;
    // Error: lvalue required as increment operand
}    
{
//>new
    double* dp {new double}; // reserveer een double
    int i; cin >> i;
    double* drij {new double[i]}; // reserveer een array met i doubles
    // ...
    delete dp; // geef de door dp aangewezen geheugenruimte vrij
    delete[] drij; // idem voor de door drij aangewezen array
//<new
}
}
