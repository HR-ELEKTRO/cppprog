#include <iostream>
#include <cassert>
using namespace std;

//>abs_not_overloaded
int abs_int(int i) {
    if (i < 0) return -i; else return i;
}
double abs_double(double f) {
    if (f < 0) return -f; else return f;
}
//<abs_not_overloaded

//>abs_overloaded
int abs(int i) {
    if (i < 0) return -i; else return i;
}
double abs(double f) {
    if (f < 0) return -f; else return f;
}
//<abs_overloaded

//>def_par
void print(int i, int talstelsel = 10);
//<def_par

void print(int i, int talstelsel) {
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
    Breuk& operator+=(const Breuk& right);
    Breuk& operator++();         // prefix
    const Breuk operator++(int); // postfix
private:
    int boven;
    int onder;
    void normaliseer();
friend ostream& operator<<(ostream& out, const Breuk& b);
friend bool operator==(const Breuk& left, const Breuk& right);
};

istream& operator>>(istream& in, Breuk& b);
bool operator!=(const Breuk& left, const Breuk& right);
const Breuk operator+(const Breuk& left, const Breuk& right);

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

Breuk& Breuk::operator+=(const Breuk& right) {
    boven = boven * right.onder + onder * right.boven;
    onder *= right.onder;
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

const Breuk operator+(const Breuk& left, const Breuk& right) {
    Breuk copyLeft(left);
    copyLeft += right;
    return copyLeft;
}

ostream& operator<<(ostream& left, const Breuk& right) {
    return left << right.boven << '/' << right.onder;
}

istream& operator>>(istream& left, Breuk& right) {
    int teller;
    if (left >> teller)
        if (left.peek() == '/') {
            left.get();
            int noemer;
            if (left >> noemer) right = Breuk(teller, noemer);
            else right = Breuk(teller);
        }
        else right = Breuk(teller);
    else right = Breuk();
    return left;
}

bool operator==(const Breuk& left, const Breuk& right) {
    return left.boven == right.boven && left.onder == right.onder;
}

bool operator!=(const Breuk& left, const Breuk& right) {
    return !(left == right);
}

//>Breuk3_main
int main() {
    Breuk b1, b2;              // definiëren van variabelen
    cout << "Geef Breuk: ";
    cin >> b1;                 // inlezen met >>
    cout << "Geef nog een Breuk: ";
    cin >> b2;                 // inlezen met >>
    cout << b1 << "+"          // afdrukken met <<
         << b2 << "="
         << (b1 + b2) << endl; // optellen met +
    Breuk b3{18, -9};          // definiëren en initialiseren
    if (b1 != b3) {            // vergelijken met !=
        b3++;                  // verhogen met ++
    }
    cout << b3 << endl;        // afdrukken met <<
    b3 += 5;                   // verhogen met +=
    cout << b3 << endl;        // afdrukken met <<
    if (-2 == b3) {            // vergelijken met een int
        cout << "OK." << endl;
    } 
//<Breuk3_main
//>Breuk3_main2
    else {
        cout << "Error." << endl;
    }

    cin.get();                 // wacht met sluiten console-
    cin.get();                 // window 
    return 0;
}
//<Breuk3_main2

void dummy() {
{
//>som_in_C
    int array[] = {12, 2, 17, 32, 1, 18};
    size_t i, aantal = sizeof array / sizeof array[0];
    int som = 0;
    for (i = 0; i < aantal; i++) {
        som += array[i];
    }
//<som_in_C
}
{
//>som_in_Cpp_zonder_auto
    int array[] {12, 2, 17, 32, 1, 18};
    int som = 0;
    for (int element: array) {
        som += element;
    }
//<som_in_Cpp_zonder_auto
}
{
//>use_abs_overloaded
    double in;
    std::cin >> in; // lees in
    std::cout << abs(in) << '\n'; // druk de absolute waarde van in af
//<use_abs_overloaded
}
{
    
//>use_def_par
    print(5, 2);  // uitvoer: 101
    print(5);     // uitvoer: 5
    print(5, 10); // uitvoer: 5
//<use_def_par
}
{
//>use_struct_C
    struct Tijdsduur td1;
//<use_struct_C
}
{
//>struct_typedef
typedef struct Tijdsduur TTijdsduur;
//<struct_typedef
//>use_struct_typedef
    TTijdsduur td2;
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
    std::cout << "a = " << '\n';
    // a = b++++;
    // Error: lvalue required as increment operand
}    
{
//>new
    double* dp{new double}; // reserveer een double
    int i; cin >> i;
    double* drij{new double[i]}; // reserveer een array met i doubles
    // ...
    delete dp; // geef de door dp aangewezen geheugenruimte vrij
    delete[] drij; // idem voor de door drij aangewezen array
//<new
}
}
