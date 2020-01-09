// Een dozijn van een willekeurig type T

#include <iostream>
#include <string>
using namespace std;

template<typename T> class Dozijn {
public:
    void zet_in(int index, const T& waarde);
    const T& lees_uit(int index) const;
private:
    T data[12];
};

template<typename T> void Dozijn<T>::zet_in(int index, const T& waarde) {
    if (index >= 0 && index < 12) 
        data[index] = waarde;
}

template<typename T> const T& Dozijn<T>::lees_uit(int index) const {
    if (index < 0)
        index = 0;
    if (index > 11)
        index = 11;
    return data[index];
}

template<typename T> ostream& operator<<(ostream& o, const Dozijn<T>& d) {
    o << d.lees_uit(0);
    for (int i = 1; i < 12; ++i)
        o << ", " << d.lees_uit(i);
    return o;
}

int main() {
    Dozijn<int> kwadraten;
    for (int j {0}; j < 12; ++j)
        kwadraten.zet_in(j, j * j);
    cout << "kwadraten = " << kwadraten << '\n';
    Dozijn<string> provincies;
    provincies.zet_in(0, "Drenthe");
    provincies.zet_in(1, "Flevoland");
    provincies.zet_in(2, "Friesland");
    provincies.zet_in(3, "Gelderland");
    provincies.zet_in(4, "Groningen");
    provincies.zet_in(5, "Limburg");
    provincies.zet_in(6, "Noord-Brabant");
    provincies.zet_in(7, "Noord-Holland");
    provincies.zet_in(8, "Overijssel");
    provincies.zet_in(9, "Utrecht");
    provincies.zet_in(10, "Zeeland");
    provincies.zet_in(11, "Zuid-Holland");
    cout << "provincies = " << provincies << '\n';   
}
