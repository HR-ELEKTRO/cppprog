import std;
using namespace std;

int main() {
    list l {-3, -4, 3, 4};
//  Zoeken met behulp van een lambda functie als zoekvoorwaarde.
//  Gebruik auto als parametertype.
    auto r {find_if(l.cbegin(), l.cend(), [](auto i) {
            return i >= 0;
        })
    };
    if (r != l.end()) {
        println("Het eerste positieve element is: {}", *r);
    }
}
