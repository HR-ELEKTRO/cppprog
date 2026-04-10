import std;
using namespace std;

class Breuk {
public:
    Breuk(int b, int o): boven{b}, onder{o} {
        println("Er is een breuk met de waarde {}/{} aangemaakt.", boven, onder);
    }
    Breuk(const Breuk& b): boven{b.boven}, onder{b.onder} {
        println("Er is een breuk met de waarde {}/{} gekopieerd.", boven, onder);
    }
    ~Breuk() {
        println("Er is een breuk met de waarde {}/{} verwijderd.", boven, onder);
    }
private:
    int boven;
    int onder;
};

int main() {
    vector<Breuk> v;
    v.reserve(2);
    println("1/2 toevoegen met push_back:");
    v.push_back(Breuk {1, 2});
    println("3/4 toevoegen met emplace_back:");
    v.emplace_back(3, 4);
    println("Einde van het programma:");
}
