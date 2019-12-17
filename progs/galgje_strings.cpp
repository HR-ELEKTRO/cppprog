#include <iostream>
#include <string>
using namespace std;

int main() {
    string w = "galgje";
    string geraden(w.length(), '.');
    do {
        cout << geraden << endl << "Raad een letter: ";
        char c = cin.get(); cin.get();
        for (string::size_type i = 0; i < w.length(); ++i) {
            if (w[i] == c) {
                geraden[i] = c;
            }
        }
    }
    while (geraden != w);
    cout << "Je hebt het woord \"" << w << "\" geraden." << endl;
    cin.get(); 
    return 0;
}

