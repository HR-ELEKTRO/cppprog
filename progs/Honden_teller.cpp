import std;
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

int Hond::aantal_honden {0};

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
    println("Er zijn nu {} honden.", Hond::aantal());
    {
        Hond h1 {"Boris"};
        h1.blaf();
        println("Er zijn nu {} honden.", Hond::aantal());
        Hond h2 {"Fikkie"};
        h2.blaf();
        println("Er zijn nu {} honden.", Hond::aantal());
    }
    println("Er zijn nu {} honden.", Hond::aantal());
}
