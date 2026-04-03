import std;
using namespace std;

int main() {
    string w {"galgje"};
    string geraden (w.length(), '.');
    do {
        print("{}\nRaad een letter: ", geraden);
        char c {static_cast<char>(cin.get())}; cin.get();
        transform(w.cbegin(), w.cend(), geraden.cbegin(), geraden.begin(), [c](char cw, char cg) {
            return c == cw ? cw : cg;
        });
        print("De letter '{}' komt {} keer voor in het te raden woord.\n", c, count(w.cbegin(), w.cend(), c));
    }
    while (geraden != w);
    print("Je hebt het woord \"{}\" geraden.\n", w);
}
