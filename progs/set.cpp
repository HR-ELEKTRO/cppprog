import std;
using namespace std;

int main() {
    set<string> docenten {"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    println("De set bevat: {:n:s}", docenten);
    auto result {docenten.insert("Harry")};
    if (!result.second)
        println("1 Harry is genoeg.");
    println("Er is {} Ron.", docenten.count("Ron"));
    docenten.erase("Harry");
    println("De set bevat: {:n:s}", docenten);
}
