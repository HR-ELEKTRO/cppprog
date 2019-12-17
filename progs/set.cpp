#include <iostream>
#include <string>
#include <set>
using namespace std;

void print(const set<string>& s) {
    cout << "De set bevat: ";
    for (const auto& e: s)
        cout << e << " ";
    cout << endl;
}

int main() {
    set<string> docenten {"Jesse", "Paul", "Ineke", "Harry"};
    docenten.insert("Paul");
    print(docenten);
    auto result = docenten.insert("Harry");
    if (!result.second)
        cout << "1 Harry is genoeg." << endl;
    cout << "Er is " << docenten.count("Jesse") << " Jesse." << endl;
    docenten.erase("Harry");
    print(docenten);
    cin.get();
    return 0;
}
