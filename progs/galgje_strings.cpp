import std;
using namespace std;

int main() {
    string w {"galgje"};
    string geraden (w.length(), '.');
    do {
        print("{}\nRaad een letter: ", geraden);
        char c {static_cast<char>(cin.get())}; cin.get();
        int count {0};
        for (string::size_type i {0}; i < w.length(); ++i) {
            if (w[i] == c) {
                geraden[i] = c;
                ++count;
            }
        }
        println("De letter '{}' komt {} keer voor in het te raden woord.", c, count);
    }
    while (geraden != w);
    println("Je hebt het woord \"{}\" geraden.", w);
}
