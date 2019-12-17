#include <iostream>

using namespace std;

enum class Stoplicht {groen, oranje, rood};

ostream& operator<<(ostream& os, Stoplicht s) {
    switch (s) {
    case Stoplicht::groen:
        os<<"groen";
        break;
    case Stoplicht::oranje:
        os<<"oranje";
        break;
    case Stoplicht::rood:
        os<<"rood";
        break;
    }
    return os;
}

int main()
{
    Stoplicht s = Stoplicht::rood;
    cout << "s = " << s << '\n';
    return 0;
}
