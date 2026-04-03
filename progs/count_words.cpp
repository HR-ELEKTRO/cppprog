import std;
using namespace std;

int main() {
    string w;
    map<string, int> freq;
    println("Geef filenaam: ");
    cin >> w;
    ifstream fin {w};
    while (fin >> w) {
        ++freq[w];
    }
    println("woordfrequentie: {}", freq);
    println("Enkele belangrijke keywords:");
    println("if: {}", freq["if"]);
    println("else: {}", freq["else"]);
    println("for: {}", freq["for"]);
    println("while: {}", freq["while"]);
}
