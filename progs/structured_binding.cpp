#include <iostream>

using namespace std;

struct Adres {
    string straatnaam;
    int huisnummer;
    string plaatsnaam;
};

Adres adreslocatie_HR(const string& locatie) {
    if (locatie == "AP")
        return {"G.J. de Jonghweg", 4, "Rotterdam"};
    else if (locatie == "MP")
        /* ... */;
    return {"", 0, ""};
}

int main() {
    // Zonder stuctured binding:
    Adres ap {adreslocatie_HR("AP")};
    cout << "Het adres van de locatie AP van de HR is: "
         << ap.straatnaam << ' ' << ap.huisnummer << ", " << ap.plaatsnaam << '\n';
    
    // Met stuctured binding:
    auto [straat, nr, plaats] {adreslocatie_HR("AP")};
    cout << "Het adres van de locatie AP van de HR is: "
         << straat << ' ' << nr << ", " << plaats << '\n';
}
