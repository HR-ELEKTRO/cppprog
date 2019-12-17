#include <iostream>
#include <string>

using namespace std;

class Hond {
public:
    Hond(const string& n);
    ~Hond();
    void blaf() const;
    static int aantal();
private:
    string naam;
    static int aantalHonden;
};

int Hond::aantalHonden = 0;

Hond::Hond(const string& n): naam(n) {
    ++aantalHonden;
}
Hond::~Hond() {
    --aantalHonden;
}
int Hond::aantal() {
    return aantalHonden;
}
void Hond::blaf() const {
    cout << naam << " zegt: WOEF" << endl;
}

int main() {
    cout << "Er zijn nu " << Hond::aantal() << " honden." << endl;
    {
        Hond h1("Boris");
        h1.blaf();
        cout << "Er zijn nu " << Hond::aantal() << " honden." << endl;
        Hond h2("Fikkie");
        h2.blaf();
        cout << "Er zijn nu " << Hond::aantal() << " honden." << endl;
    }
    cout << "Er zijn nu " << Hond::aantal() << " honden." << endl;
    cin.get();
    return 0;
}
