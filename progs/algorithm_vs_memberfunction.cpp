import std;
using namespace std;

int main() {
    list l {12, 18, 6};
    // sort(l.begin(), l.end()); // O(n log n) heeft random access iteratoren nodig lijst levert bidirectionele iteratoren
    //  Error (115 regels) belangrijkste mededeling:
    //  error: no match for 'operator-' (operand types are 'std::_List_iterator<int>' and 'std::_List_iterator<int>')

    l.sort(); // O(n log n)
    println("{}", l);

    set s {12, 6, 18};
    println("{}", s);
    auto i1 {find(s.cbegin(), s.cend(), 12)}; // O(n)
    if (i1 != s.cend())
        println("{} gevonden", *i1);
    auto i2 {s.find(12)}; // O(log n)
    if (i2 != s.cend())
        println("{} gevonden", *i2);
}
