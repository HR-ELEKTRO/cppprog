#include <iostream>
#include <string>
#include <set>
using namespace std;

void print(const multiset<string>& bag) {
    cout << "De bag bevat: ";
    for (const auto& e: bag)
        cout << e << " ";
    cout << '\n';
}

int main() {
    multiset<string> docenten {"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    print(docenten);
    docenten.insert("Harry");
    print(docenten);
    docenten.insert("Harry");
    print(docenten);
    cout << "Er zijn " << docenten.count("Harry") << " Harry's.\n";
    docenten.erase(docenten.find("Harry"));
    print(docenten);
    docenten.erase("Harry");
    print(docenten);
    docenten.erase(docenten.find("Elles"));
    print(docenten);
    docenten.erase(docenten.find("Ron"), docenten.end());
    print(docenten);
}
