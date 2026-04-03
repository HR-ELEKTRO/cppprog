import std;
using namespace std;

int main() {
    set<string> docenten {"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    println("De set bevat: {}", docenten);
    auto [itr, gelukt] {docenten.insert("Harry")};
    if (!gelukt)
        println("1 Harry is genoeg.");
    println("Er is {} Ron.", docenten.count("Ron"));
    docenten.erase("Harry");
    println("De set bevat: {}", docenten);
}
