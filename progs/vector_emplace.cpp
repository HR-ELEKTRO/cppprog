#include <iostream>
#include <vector>
using namespace std;

class Breuk {
public:
    Breuk(int b, int o): boven{b}, onder{o} {
        cout << "Er is een breuk met de waarde " << boven << '/' << onder << " aangemaakt.\n";
    }
    Breuk(const Breuk& b): boven{b.boven}, onder{b.onder} {
        cout << "Er is een breuk met de waarde " << boven << '/' << onder << " gekopieerd.\n";
    }
    ~Breuk() {
    cout << "Er is een breuk met de waarde " << boven << '/' << onder << " verwijderd.\n";
    }
private:
    int boven;
    int onder;
};


int main() {
    vector<Breuk> v;
    v.reserve(2);
    cout << "1/2 toevoegen met push_back:\n";
    v.push_back(Breuk{1, 2});
    cout << "3/4 toevoegen met emplace_back:\n";
    v.emplace_back(3, 4);
    cout << "Einde van het programma:\n";
}
