import std;
using namespace std;

int main() {
    string w {"galgje"};
    set<char> te_raden, geraden;
    ranges::copy(w, inserter(te_raden, te_raden.begin()));
    do {
        for (auto c: w) {
            print("{}", geraden.count(c) ? c : '.');
        }
        print("\nRaad een letter: ");
        char c {static_cast<char>(cin.get())}; cin.get();
        while (!geraden.insert(c).second) {
            print("De letter {} had je al geraden...", c);
            print("\nRaad een andere letter: ");
            c = cin.get(); cin.get();
        }
        println("De letter '{}' komt {} keer voor in het te raden woord.", c, ranges::count(w, c));
    } while (!ranges::includes(geraden, te_raden));
    println("Je hebt het woord {} geraden.", w);
}
