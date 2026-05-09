// Een dozijn van een willekeurig type T

import std;
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

// Een dozijn bool's

template<> class Dozijn<bool> {
public:
    void zet_in(int index, bool waarde);
    bool lees_uit(int index) const;
private:
    uint16_t data; // 16 bits, genoeg voor 12 booleans
};

void Dozijn<bool>::zet_in(int index, bool waarde) {
    if (index >= 0 && index < 12) {
        if (waarde) {
            data |= (1 << index);
        } else {
            data &= ~(1 << index);
        }
    }
}

bool Dozijn<bool>::lees_uit(int index) const {
    if (index < 0)
        index = 0;
    if (index > 11)
        index = 11;
    return data & (1 << index);
}

// Een dozijn pointers wil ik niet
template<typename T> class Dozijn<T*> {
public:
    Dozijn() = delete;
};

template<typename T> string naar_string(const Dozijn<T>& d) {
    string s {format("{}", d.lees_uit(0))};
    for (int i {1}; i < 12; ++i)
        s += format(", {}", d.lees_uit(i));
    return s;
}

int main() {
    Dozijn<int> kwadraten;
    for (int j {0}; j < 12; ++j)
        kwadraten.zet_in(j, j * j);
    println("kwadraten = {}", naar_string(kwadraten));
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
    println("provincies = {}", naar_string(provincies));
    println("sizeof(int) = {}", sizeof(int));
    println("sizeof(Dozijn<int>) = {}", sizeof(Dozijn<int>));
    println("sizeof(bool) = {}", sizeof(bool));
    println("sizeof(Dozijn<bool>) = {}", sizeof(Dozijn<bool>));
    Dozijn<bool> is_priem;
    is_priem.zet_in(0, false);
    is_priem.zet_in(1, false);
    is_priem.zet_in(2, true);
    is_priem.zet_in(3, true);
    is_priem.zet_in(4, false);
    is_priem.zet_in(5, true);
    is_priem.zet_in(6, false);
    is_priem.zet_in(7, true);
    is_priem.zet_in(8, false);
    is_priem.zet_in(9, false);
    is_priem.zet_in(10, false);
    is_priem.zet_in(11, true);
    println("is_priem = {}", naar_string(is_priem));
    // Dozijn<int*> dp;
    // error: use of deleted function 'Dozijn<T*>::Dozijn() [with T = int]'
}
