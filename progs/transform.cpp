import std;
using namespace std;

int telop(int i, int j) {
    return i + j;
}

int main() {
    vector v {-3, -4, 3, 4};
    vector w {1, 2, 3, 4};
    println("v: {}", v);
    println("w: {}", w);
//  Bewerking opgeven met een functie.
//  Nadeel: voor elke bewerking moet een aparte functie worden geschreven.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), telop);
    println("v na transform: {}", v);
//  Bewerking opgeven met een lambda functie.
//  Voordeel: handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), [](int i1, int i2) {
        return i1 + i2;
    });
    println("v na transform: {}", v);
//  Bewerking opgeven met een lambda functie met auto parameters.
//  Voordeel: meest handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), [](auto i1, auto i2) {
        return i1 + i2;
    });
    println("v na transform: {}", v);
//  Bewerking opgeven met een opgeslagen lambda functie.
//  Voordeel: meest handige oplossing als bewerking vaker voorkomt.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    auto add {[](int i1, int i2) {
        return i1 + i2;
    }};
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), add);
    println("v na transform: {}", v);
}
