#include <iostream>
#include <string>
#include <set>
using namespace std;

void print(const set<string>& s) {
    cout << "De set bevat: ";
    for (const auto& e: s)
        cout << e << " ";
    cout << '\n';
}

int main() {
    set<string> docenten {"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    print(docenten);
    auto [itr, gelukt] {docenten.insert("Harry")};
    if (!gelukt)
        cout << "1 Harry is genoeg.\n";
    cout << "Er is " << docenten.count("Ron") << " Ron.\n";
    docenten.erase("Harry");
    print(docenten);
}
