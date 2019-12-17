// Een dozijn integers

#include <iostream>
using namespace std;

class Dozijn {
public:
    void zetIn(int index, int waarde);
    int leesUit(int index) const;
private:
    int data[12];
};

ostream& operator<<(ostream& o, const Dozijn& v);

void Dozijn::zetIn(int index, int waarde) {
    if (index >= 0 && index < 12) 
        data[index] = waarde;
}

int Dozijn::leesUit(int index) const {
    if (index >= 0 && index < 12) 
        return data[index];
    return 0; /* ik weet niets beters */
}

ostream& operator<<(ostream& o, const Dozijn& d) {
    o << d.leesUit(0);
    for (int i = 1; i < 12; ++i)
        o << ", " << d.leesUit(i);
    return o;
}

int main() {
    Dozijn kwadraten;
    for (int j = 0; j < 12; ++j)
        kwadraten.zetIn(j, j * j);
    cout << "kwadraten = " << kwadraten << endl;
    cin.get();
    return 0;
}
