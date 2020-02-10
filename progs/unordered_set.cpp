#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void print(const unordered_set<string>& s) {
    cout << "De set bevat: ";
    for (const auto& e: s)
        cout << e << " ";
    cout << '\n';
}

int main() {
    unordered_set<string> mensen {"Ron", "Daniël", "Roy", "Harry"};
    mensen.insert("Elles");
    print(mensen);
    auto result {mensen.insert("Harry")};
    if (!result.second)
        cout << "1 Harry is genoeg.\n";
    cout << "Er is " << mensen.count("Elles") << " Elles.\n";
    mensen.erase("Harry");
    print(mensen);
    cout << "De hash table heeft " << mensen.bucket_count() << " buckets.";
    cout << "\nElke bucket bevat gemiddeld " << mensen.load_factor() << " elementen.";
    cout << "\nDe maximale load_factor is " << mensen.max_load_factor() << ".";
    cout << "\nWe voegen nu nog 24 namen toe.\n";
    mensen.insert({"Abdel", "Alia", "Amer", "Corjan", "Daan", "Daniël", "Diederik", "Erwin", "Gabriël", "Jarl", "Jasper", "Jennifer", "Jorg", "Juul", "Koen", "Mathijs", "Matthijs", "Mustafa", "Nick", "Remco", "Robin", "Soufiane", "Tim", "Umit"});
    print(mensen);
    cout << "De hash table heeft " << mensen.bucket_count() << " buckets.";
    cout << "\nElke bucket bevat gemiddeld " << mensen.load_factor() << " elementen.";
}
