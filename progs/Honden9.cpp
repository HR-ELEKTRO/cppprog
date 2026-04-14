import std;
using namespace std;

// #define ERROR // commentaar deze regel uit om de ONJUISTE copy constructor en assignment operator te laten genereren door de compiler

class Hond {
public:
    explicit Hond(string_view n);
    virtual ~Hond();
    void set_naam(string_view n);
    virtual void blaf() const =0;
private:
    string naam;
};

class Teckel: public Hond {
public:
    explicit Teckel(string_view n);
    ~Teckel() override;
    void blaf() const override;
};

class Whisky_vat {
public:
    explicit Whisky_vat(int b);
    ~Whisky_vat();
    bool geef_borrel();
private:
    int aantal_borrels;
};

Whisky_vat::Whisky_vat(int b): aantal_borrels {b} {
    println("Vat met {} borrels aangemaakt.", aantal_borrels);
}

Whisky_vat::~Whisky_vat() {
    println("Vat met {} borrels opgeruimd.", aantal_borrels);
}

bool Whisky_vat::geef_borrel() {
    if (aantal_borrels > 0) {
        --aantal_borrels;
        println("Ik kom je helpen, drink deze borrel maar op!");
        return true;
    }
    println("Ik kan je niet helpen, mijn Whisky is op.");
    return false;
}

class Sint_bernard: public Hond {
public:
    explicit Sint_bernard(string_view n); /* aanmaken van een Sint_bernard zonder Whisky_vat */
    Sint_bernard(string_view n, int b); /* aanmaken van een Sint_bernard met Whisky_vat gevuld met b borrels*/
#ifndef ERROR 
    Sint_bernard(const Sint_bernard& s);
#endif
    ~Sint_bernard() override;
#ifndef ERROR
    Sint_bernard& operator=(const Sint_bernard& r);
#endif
    void blaf() const override;
    void help();
private:
    unique_ptr<Whisky_vat> vat_ptr;
};

Hond::Hond(string_view n): naam {n} {
    println("Hoera, {} is geboren!", naam);
}

Hond::~Hond() {
    println("Helaas, {} is gestorven.", naam);
}

void Hond::set_naam(string_view n) {
    naam = n;
}

Teckel::Teckel(string_view n): Hond {n} {
    println("Er is een Teckel geboren!");
}

Teckel::~Teckel() {
    println("Er is een Teckel gestorven.");
}

void Teckel::blaf() const {
    println("Kef kef");
}

Sint_bernard::Sint_bernard(string_view n): Hond {n}, vat_ptr {nullptr} {
    println("Er is een Sint_bernard geboren!");
}

Sint_bernard::Sint_bernard(string_view n, int b): Hond {n}, vat_ptr {make_unique<Whisky_vat>(b)} {
    println("Er is een Sint_bernard geboren!");
}

#ifndef ERROR
Sint_bernard::Sint_bernard(const Sint_bernard& s): Hond {s}, vat_ptr {nullptr} {
    if (s.vat_ptr != nullptr) {
        vat_ptr = make_unique<Whisky_vat>(*(s.vat_ptr));
    }
    println("Er is een Sint_bernard gekopieerd!");
}
#endif

Sint_bernard::~Sint_bernard() {
    println("Er is een Sint_bernard bijna dood.");
    if (vat_ptr != 0) {
        while (vat_ptr->geef_borrel()) 
            /* drink alle borrels op */;
    }
    println("Er is een Sint_bernard gestorven.");
}

#ifndef ERROR
Sint_bernard& Sint_bernard::operator=(const Sint_bernard& r) {
    Sint_bernard t(r);
    Hond::operator=(t);
    std::swap(vat_ptr, t.vat_ptr);
    return *this;
}
#endif

void Sint_bernard::blaf() const {
    println("WOEF, WOEF");
}

void Sint_bernard::help() {
    if (vat_ptr != 0) {
        vat_ptr->geef_borrel();
    }
    blaf();
}

int main() {
    Sint_bernard h1 {"Boris", 10};
    h1.help();
    Sint_bernard h2 {"Blauwe_knoop"};
    h2.help();
//  Maak een kopietje van h1
    Sint_bernard h3 {h1};
    for (int i {0}; i < 5; ++i) {
        h3.help() /* help 5 keer */;
    }
    h1.help();
//  Doe een toekenning
    h3 = h2;
    h3.blaf();
    h3.help();
}

/* Uitvoer:
Hoera, Boris is geboren!
Vat met 10 borrels aangemaakt.
Er is een Sint_bernard geboren!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Hoera, Blauwe_knoop is geboren!
Er is een Sint_bernard geboren!
WOEF, WOEF
Er is een Sint_bernard gekopieerd!
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Ik kom je helpen, drink deze borrel maar op!
WOEF, WOEF
Er is een Sint_bernard gekopieerd!
Er is een Sint_bernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kan je niet helpen, mijn Whisky is op.
Er is een Sint_bernard gestorven.
Vat met 0 borrels opgeruimd.
Helaas, Blauwe_knoop is gestorven.
WOEF, WOEF
WOEF, WOEF
Er is een Sint_bernard bijna dood.
Er is een Sint_bernard gestorven.
Helaas, Blauwe_knoop is gestorven.
Er is een Sint_bernard bijna dood.
Er is een Sint_bernard gestorven.
Helaas, Blauwe_knoop is gestorven.
Er is een Sint_bernard bijna dood.
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kom je helpen, drink deze borrel maar op!
Ik kan je niet helpen, mijn Whisky is op.
Er is een Sint_bernard gestorven.
Vat met 0 borrels opgeruimd.
Helaas, Boris is gestorven.
*/

/* ERRORS ZONDER zelf gedefinieerde copy constructor en assignment operator:
Honden9.cpp:50:7: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Whisky_vat; _Dp = std::default_delete<Whisky_vat>]'
In file included from /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/memory:80,
                 from /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/x86_64-pc-cygwin/bits/stdc++.h:58,
                 from /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/std.cc:30,
of module std, imported at Honden9.cpp:1:
/usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/unique_ptr.h:525:7: note: declared here
  525 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
Honden9.cpp:50:7: note: use '-fdiagnostics-all-candidates' to display considered candidates
   50 | class Sint_bernard: public Hond {
      |       ^~~~~~~~~~~~
Honden9.cpp: In function 'int main()':
Honden9.cpp:144:24: note: use '-fdiagnostics-all-candidates' to display considered candidates
  144 |     Sint_bernard h3 {h1};
      |                        ^
Honden9.cpp:150:10: error: use of deleted function 'Sint_bernard& Sint_bernard::operator=(const Sint_bernard&)'
  150 |     h3 = h2;
      |          ^~
Honden9.cpp:50:7: note: 'Sint_bernard& Sint_bernard::operator=(const Sint_bernard&)' is implicitly deleted because the default definition would be ill-formed:
   50 | class Sint_bernard: public Hond {
      |       ^~~~~~~~~~~~
Honden9.cpp: At global scope:
Honden9.cpp:50:7: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Whisky_vat; _Dp = std::default_delete<Whisky_vat>]'
/usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/unique_ptr.h:526:19: note: declared here
  526 |       unique_ptr& operator=(const unique_ptr&) = delete;
      |                   ^~~~~~~~
Honden9.cpp:50:7: note: use '-fdiagnostics-all-candidates' to display considered candidates
   50 | class Sint_bernard: public Hond {
      |       ^~~~~~~~~~~~
*/
