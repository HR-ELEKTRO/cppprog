import std;
using namespace std;

int main() {
    unordered_set<string> mensen {"Ron", "Daniël", "Roy", "Harry"};
    mensen.insert("Elles");
    println("De set bevat: {:n:s}", mensen);
    auto result {mensen.insert("Harry")};
    if (!result.second)
        println("1 Harry is genoeg.");
    println("Er is {} Elles.", mensen.count("Elles"));
    mensen.erase("Harry");
    println("De set bevat: {:n:s}", mensen);
    println("De hash table heeft {} buckets.", mensen.bucket_count());
    println("Elke bucket bevat gemiddeld {} elementen.", mensen.load_factor());
    println("De maximale load_factor is {}.", mensen.max_load_factor());
    println("We voegen nu nog 21 namen toe.");
    mensen.insert({"Amir", "Martijn", "Ashwin", "Nicholas", "Deniz", "Mitchel", "Sietse", "Robin", "Bálint", "Dewin", "Connor", "Nino", "Alexander", "Jennifer", "Leendert", "Maurice", "Thomas", "Bas", "Wesley", "Finley", "Jasper"});
    println("De set bevat: {:n:s}", mensen);
    println("De hash table heeft {} buckets.", mensen.bucket_count());
    println("Elke bucket bevat gemiddeld {} elementen.", mensen.load_factor());
}
