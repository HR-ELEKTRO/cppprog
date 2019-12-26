#include <iostream>
using namespace std;

string resultaat_naar_tekst(int resultaat) {
    string s;
    switch (resultaat) {
        case 1:
        case 2: s = "slecht"; break;
        case 3:
        case 4:
        case 5: s = "on"; [[fallthrough]];
        case 6: 
        case 7: s += "voldoende"; break;
        case 8:
        case 9: s = "goed"; break;
        case 10: s = "uitstekend"; break;
        default: return "ongeldig";
    }
    switch (resultaat) {
        case 1: 
        case 9: return "zeer " + s; 
        case 3:
        case 7: return "ruim " + s;
        case 5: return "net " + s;
        default: return s;
    }
}

int main() {
    for (int r = 0; r < 12; ++r) {
        cout << r << ": " << resultaat_naar_tekst(r) << '\n';
    }
    [[maybe_unused]] string s{resultaat_naar_tekst(42)};
    [[maybe_unused]] int i;
}