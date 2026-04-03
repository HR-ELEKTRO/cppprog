import std;
using namespace std;

bool is_pos(int i) {
    return i >= 0;
}

template<totally_ordered T>
class Is_greater_equal {
public:
    Is_greater_equal(T r): right(r) {
    }
    bool operator()(T left) const {
        return left >= right;
    }
private:
    T right;
};

int main() {
    list l {-3, -4, 3, 4};
//  Zoeken met behulp van een functie als zoekvoorwaarde.
//  Nadeel: voor elke zoekvoorwaarde moet een aparte 
//  functie worden geschreven.
    auto r {find_if(l.cbegin(), l.cend(), is_pos)};
    if (r != l.cend()) {
        println("Het eerste positieve element is: {}", *r);
    }
//  Zoeken met behulp van een functie-object als zoekvoorwaarde.
//  Voordeel: flexibeler dan een functie.
//  Nadeel: voor elke vergelijkings operator moet een
//  apart functie-object worden geschreven.
    r = find_if(l.cbegin(), l.cend(), Is_greater_equal(0));
    if (r != l.cend()) {
        println("Het eerste positieve element is: {}", *r);
    }
//  Zoeken met behulp van een lambda functie als zoekvoorwaarde.
//  Voordeel: handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    r = find_if(l.cbegin(), l.cend(), [](int i) {
        return i >= 0;
    });
    if (r != l.end()) {
        println("Het eerste positieve element is: {}", *r);
    }
//  Zoeken met behulp van een lambda functie met auto parameter als zoekvoorwaarde.
//  Voordeel: meest handige oplossing als zoekvoorwaarde uniek is.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    r = find_if(l.cbegin(), l.cend(), [](auto i) {
        return i >= 0;
    });
    if (r != l.end()) {
        println("Het eerste positieve element is: {}", *r);
    }
//  Zoeken met behulp van een opgeslagen lambda functie als zoekvoorwaarde.
//  Voordeel: meest handige oplossing als zoekvoorwaarde vaker voorkomt.
//  Nadeel: lambda funties hebben een speciale, niet heel leesbare, syntax.
    auto is_positief {[](auto i) {
        return i >= 0;
    }};
    r = find_if(l.cbegin(), l.cend(), is_positief);
    if (r != l.end()) {
        println("Het eerste positieve element is: {}", *r);
    }
}
