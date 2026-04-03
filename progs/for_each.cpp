import std;
using namespace std;

void print_dubbel(int i) {
    print("{0} {0} ", i);
}

int main() {
    vector v {-3, -4, 3, 4};
    println("{:n}", v);
//  Bewerking opgeven met een functie.
//  Nadeel: voor elke bewerking moet een aparte functie worden geschreven.
    for_each(v.cbegin(), v.cend(), print_dubbel);
    println();
//  Bewerking opgeven met een lambda functie.
//  Voordeel: handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    for_each(v.cbegin(), v.cend(), [](int i) {
        print("{0} {0} ", i);
    });
    println();
//  Bewerking opgeven met een lambda functie met auto parameter.
//  Voordeel: meest handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    for_each(v.cbegin(), v.cend(), [](auto i) {
        print("{0} {0} ", i);
    });
    println();
//  Bewerking opgeven met een opgeslagen lambda functie.
//  Voordeel: meest handige oplossing als bewerking vaker voorkomt.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    auto print_twice {[](auto i) {
        print("{0} {0} ", i);
    }};
    for_each(v.cbegin(), v.cend(), print_twice);
    println();
//  Alternatief voor for_each met lambda functie: gebruik range-based for.
//  Voordeel: eenvoudigere syntax.
//  Nadeel: werkt alleen als de gehele container doorlopen moet worden,
//  for_each kan ook gebruikt worden om een deel van een container te 
//  doorlopen.
    for (auto i: v) {
        print("{0} {0} ", i);
    };
    println();
}
