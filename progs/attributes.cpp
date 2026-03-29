import std;
using namespace std;

string resultaat_naar_tekst(int resultaat) {
    string s;
    switch (resultaat) {
        case 1: s = "zeer "; [[fallthrough]];
        case 2: s += "slecht"; break;
        case 5: s = "net "; [[fallthrough]]; 
        case 3: 
        case 4: s += "onvoldoende"; break;
        case 7: s = "ruim "; [[fallthrough]];
        case 6: s += "voldoende"; break;
        case 9: s = "zeer "; [[fallthrough]];
        case 8: s += "goed"; break;
        case 10: s = "uitstekend"; break;
        default: s = "ongeldig";
    }
    return s;
}

int main() {
    for (int r {0}; r < 12; ++r) {
        println("{}: {}", r, resultaat_naar_tekst(r));
    }
    [[maybe_unused]] string s {resultaat_naar_tekst(42)};
}