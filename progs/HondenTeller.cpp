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
    static int aantal_honden;
};

int Hond::aantal_honden = 0;

Hond::Hond(const string& n): naam{n} {
    ++aantal_honden;
}
Hond::~Hond() {
    --aantal_honden;
}
int Hond::aantal() {
    return aantal_honden;
}
void Hond::blaf() const {
    cout << naam << " zegt: WOEF\n";
}

int main() {
    cout << "Er zijn nu " << Hond::aantal() << " honden.\n";
    {
        Hond h1{"Boris"};
        h1.blaf();
        cout << "Er zijn nu " << Hond::aantal() << " honden.\n";
        Hond h2{"Fikkie"};
        h2.blaf();
        cout << "Er zijn nu " << Hond::aantal() << " honden.\n";
    }
    cout << "Er zijn nu " << Hond::aantal() << " honden.\n";
}
