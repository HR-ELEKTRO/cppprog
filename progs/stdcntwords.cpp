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
    ifstream fin(w);
    while (fin >> w) {
        ++freq[w];
    }
    for (const auto& wordcount: freq) {
        cout << wordcount.first << " " << wordcount.second << endl;
    }
    cout << "Enkele belangrijke keywords:" << endl;
    cout << "do: " << freq["do"] << endl;
    cout << "else: " << freq["else"] << endl;
    cout << "for: " << freq["for"] << endl;
    cout << "if: " << freq["if"] << endl;
    cout << "return: " << freq["return"] << endl;
    cout << "switch: " << freq["switch"] << endl;
    cout << "while: " << freq["while"] << endl;
    cin.get();
    cin.get();
    return 0;
}
