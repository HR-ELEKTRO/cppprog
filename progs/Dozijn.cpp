// Een dozijn integers

#include <iostream>
using namespace std;

class Dozijn {
public:
    void zet_in(int index, int waarde);
    int lees_uit(int index) const;
private:
    int data[12];
};

ostream& operator<<(ostream& o, const Dozijn& v);

void Dozijn::zet_in(int index, int waarde) {
    if (index >= 0 && index < 12) 
        data[index] = waarde;
}

int Dozijn::lees_uit(int index) const {
    if (index >= 0 && index < 12) 
        return data[index];
    return 0; /* ik weet niets beters */
}

ostream& operator<<(ostream& o, const Dozijn& d) {
    o << d.lees_uit(0);
    for (int i = 1; i < 12; ++i)
        o << ", " << d.lees_uit(i);
    return o;
}

int main() {
    Dozijn kwadraten;
    for (int j {0}; j < 12; ++j)
        kwadraten.zet_in(j, j * j);
    cout << "kwadraten = " << kwadraten << '\n';
}
