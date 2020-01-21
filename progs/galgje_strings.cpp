#include <iostream>
#include <string>
using namespace std;

int main() {
    string w {"galgje"};
    string geraden (w.length(), '.');
    do {
        cout << geraden << "\nRaad een letter: ";
        char c {static_cast<char>(cin.get())}; cin.get();
        int count {0};
        for (string::size_type i {0}; i < w.length(); ++i) {
            if (w[i] == c) {
                geraden[i] = c;
                ++count;
            }
        }
        cout << "De letter '" << c << "' komt " << count << " keer voor in het te raden woord.\n";
    }
    while (geraden != w);
    cout << "Je hebt het woord \"" << w << "\" geraden.\n";
}
