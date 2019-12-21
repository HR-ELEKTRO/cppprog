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
    set<string> docenten{"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    print(docenten);
    auto result{docenten.insert("Harry")};
    if (!result.second)
        cout << "1 Harry is genoeg.\n";
    cout << "Er is " << docenten.count("Ron") << " Ron.\n";
    docenten.erase("Harry");
    print(docenten);
}
