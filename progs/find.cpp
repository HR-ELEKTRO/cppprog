import std;
using namespace std;

int main() {
    string w {"galgje"}; 
    vector<bool> gevonden (w.size(), false);
    do {
        for (string::size_type i {0}; i < w.size(); ++i) {
            print("{}", gevonden[i] ? w[i] : '.');
        }
        print("\nRaad een letter: ");
        char c {static_cast<char>(cin.get())}; cin.get();
        auto itr {w.cbegin()};
        int count {0};
        while ((itr = find(itr, w.cend(), c)) != w.cend()) {
            gevonden[(itr - w.cbegin())] = true;
            ++itr;
            ++count;
        }
        println("De letter '{}' komt {} keer voor in het te raden woord.", c, count);
    }
    while (count(gevonden.begin(), gevonden.end(), false) != 0);
    println("Je hebt het woord \"{}\" geraden.", w);
}
