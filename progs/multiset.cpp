import std;
using namespace std;

int main() {
    multiset<string> docenten {"Ron", "Daniël", "Roy", "Harry"};
    docenten.insert("Elles");
    println("De multiset bevat: {:n:s}", docenten);
    docenten.insert("Harry");
    println("De multiset bevat: {:n:s}", docenten);
    docenten.insert("Harry");
    println("De multiset bevat: {:n:s}", docenten);
    println("Er zijn {} Harry's.", docenten.count("Harry"));
    docenten.erase(docenten.find("Harry"));
    println("De multiset bevat: {:n:s}", docenten);
    docenten.erase("Harry");
    println("De multiset bevat: {:n:s}", docenten);
    docenten.erase(docenten.find("Elles"));
    println("De multiset bevat: {:n:s}", docenten);
    docenten.erase(docenten.find("Ron"), docenten.end());
    println("De multiset bevat: {:n:s}", docenten);
}
