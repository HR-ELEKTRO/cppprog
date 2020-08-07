#include <iostream>

using namespace std;

enum class Stoplicht {groen, oranje, rood};

ostream& operator<<(ostream& out, Stoplicht s) {
    switch (s) {
    case Stoplicht::groen:
        out<<"groen";
        break;
    case Stoplicht::oranje:
        out<<"oranje";
        break;
    case Stoplicht::rood:
        out<<"rood";
        break;
    }
    return out;
}

int main()
{
    Stoplicht s {Stoplicht::rood};
    cout << "s = " << s << '\n';
}
