#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
    string w;
    map<string, int> freq;
    cout << "Geef filenaam: ";
    cin >> w;
    ifstream fin {w};
    while (fin >> w) {
        ++freq[w];
    }
    for (const auto& wordcount: freq) {
        cout << wordcount.first << " " << wordcount.second << '\n';
    }
    cout << "Enkele belangrijke keywords:\n";
    cout << "do: " << freq["do"] << '\n';
    cout << "else: " << freq["else"] << '\n';
    cout << "for: " << freq["for"] << '\n';
    cout << "if: " << freq["if"] << '\n';
    cout << "return: " << freq["return"] << '\n';
    cout << "switch: " << freq["switch"] << '\n';
    cout << "while: " << freq["while"] << '\n';
}
