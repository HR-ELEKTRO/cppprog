import std;
using namespace std;

int main() {
    vector v {-3, -4, 3, 4};
    vector w {1, 2, 3, 4};
    println("v: {}", v);
    println("w: {}", w);
    
//  Bewerking opgeven met een standaard functie-object.
//  Voordeel: hergebruik van standaardcomponenten.
    transform(v.cbegin(), v.cend(), w.cbegin(), v.begin(), plus());
    println("v na transform: {}", v);
}
