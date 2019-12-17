#include <iostream>
#include <string>
#include <set>
using namespace std;

void print(const multiset<string>& bag) {
    cout << "De bag bevat: ";
    for (const auto& e: bag)
        cout << e << " ";
    cout << endl;
}

int main() {
    multiset<string> docenten {"Harrie", "Jesse", "Paul", "Ineke", "Harry", };
    docenten.insert("Paul");
    print(docenten);
    docenten.insert("Harry");
    print(docenten);
    cout << "Er zijn " << docenten.count("Harry") << " Harry's." << endl;
    docenten.erase("Harry");
    print(docenten);
    docenten.erase(docenten.find("Paul"));
    print(docenten);
    docenten.erase(docenten.find("Ineke"), docenten.end());
    print(docenten);
    cin.get();
    return 0;
}