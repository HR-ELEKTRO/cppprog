#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> m{{"Harry", 1}, {"Ron", 2}, {"Daniel", 3}};
    for (const auto [key, value]: m) {
        cout << key << " = " << value << '\n';
    }
    // probeer een nieuw item toe te voegen:
    auto [iterator, gelukt]{m.insert({"Harry", 4})};
    if (!gelukt) {
        cout << "Harry zat al in de map" << endl;
        // pas bestaande item aan:
        m["Harry"] = 4;
    }
    for (const auto [key, value]: m) {
        cout << key << " = " << value << '\n';
    }
}
