// Een dozijn van een willekeurig type T

#include <iostream>
#include <string>
using namespace std;

template<typename T> class Dozijn {
public:
    void zetIn(int index, const T& waarde);
    const T& leesUit(int index) const;
private:
    T data[12];
};

template<typename T> void Dozijn<T>::zetIn(int index, const T& waarde) {
    if (index >= 0 && index < 12) 
        data[index] = waarde;
}

template<typename T> const T& Dozijn<T>::leesUit(int index) const {
    if (index < 0)
        index = 0;
    if (index > 11)
        index = 11;
    return data[index];
}

template<typename T> ostream& operator<<(ostream& o, const Dozijn<T>& d) {
    o << d.leesUit(0);
    for (int i = 1; i < 12; ++i)
        o << ", " << d.leesUit(i);
    return o;
}

int main() {
    Dozijn<int> kwadraten;
    for (int j = 0; j < 12; ++j)
        kwadraten.zetIn(j, j * j);
    cout << "kwadraten = " << kwadraten << endl;
    Dozijn<string> provincies;
    provincies.zetIn(0, "Drenthe");
    provincies.zetIn(1, "Flevoland");
    provincies.zetIn(2, "Friesland");
    provincies.zetIn(3, "Gelderland");
    provincies.zetIn(4, "Groningen");
    provincies.zetIn(5, "Limburg");
    provincies.zetIn(6, "Noord-Brabant");
    provincies.zetIn(7, "Noord-Holland");
    provincies.zetIn(8, "Overijssel");
    provincies.zetIn(9, "Utrecht");
    provincies.zetIn(10, "Zeeland");
    provincies.zetIn(11, "Zuid-Holland");
    cout << "provincies = " << provincies << endl;   
    cin.get();
    return 0;
}
