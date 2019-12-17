#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void print(const unordered_set<string>& s) {
    cout << "De set bevat: ";
    for (const auto& e: s)
        cout << e << " ";
    cout << endl;
}

int main() {
    unordered_set<string> mensen = {"Jesse", "Paul", "Ineke", "Harry"};
    mensen.insert("Paul");
    print(mensen);
    auto result = mensen.insert("Harry");
    if (!result.second)
        cout << "1 Harry is genoeg." << endl;
    cout << "Er is " << mensen.count("Jesse") << " Jesse." << endl;
    mensen.erase("Harry");
    print(mensen);
    cout << "De hash table heeft " << mensen.bucket_count() << " buckets.";
    cout << endl << "Elke bucket bevat gemiddeld " << mensen.load_factor() << " elementen.";
    cout << endl << "De maximale load_factor is " << mensen.max_load_factor() << ".";
    cout << endl << "We voegen nu nog 34 namen toe." << endl;
    mensen.insert({"Sebastiaan", "Patrick", "Bas", "Ivan", "Eric", "Ralf", "Leo", "Rens", "Mark", "Jaap", "Pascal", "Arend", "Patrick", "Daniël", "Tom", "Jelle", "Raymond", "Rick", "Miguel", "Niels", "Chesron", "Bart", "David", "Remko", "Thijs", "Richard", "Robin", "Remy", "Nakib", "René", "Tako", "Maikel", "Jory", "Willem-Pieter"});
    print(mensen);
    cout << "De hash table heeft " << mensen.bucket_count() << " buckets.";
    cout << endl << "Elke bucket bevat gemiddeld " << mensen.load_factor() << " elementen.";
    cin.get();
    return 0;
}