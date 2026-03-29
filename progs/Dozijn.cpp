// Een dozijn integers

import std;
using namespace std;

class Dozijn {
public:
    void zet_in(int index, int waarde);
    int lees_uit(int index) const;
private:
    int data[12];
};

ostream& operator<<(ostream& out, const Dozijn& v);

void Dozijn::zet_in(int index, int waarde) {
    if (index >= 0 && index < 12) 
        data[index] = waarde;
}

int Dozijn::lees_uit(int index) const {
    if (index >= 0 && index < 12) 
        return data[index];
    return 0; /* ik weet niets beters */
}

ostream& operator<<(ostream& out, const Dozijn& d) {
    out << d.lees_uit(0);
    for (int i {1}; i < 12; ++i)
        out << ", " << d.lees_uit(i);
    return out;
}

template<>
struct std::formatter<Dozijn>: public formatter<string> {
    auto format(const Dozijn& d, auto& context) const {
        ostringstream ss;
        ss << d;
        return formatter<string>::format(ss.str(), context);
    }
};

template<>
struct std::formatter<Dozijn>: public formatter<string> {
    auto format(const Dozijn& d, auto& context) const {
        context.advance_to(format_to(context.out(), "{}", d.lees_uit(0)));
        for (int i {1}; i < 12; ++i)
            context.advance_to(format_to(context.out(), ", {}", d.lees_uit(i)));
        return context.out();
    }
};

int main() {
    Dozijn kwadraten;
    for (int j {0}; j < 12; ++j)
        kwadraten.zet_in(j, j * j);
    println("kwadraten = {}", kwadraten);
}
