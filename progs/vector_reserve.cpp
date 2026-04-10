import std;
using namespace std;
    
int main() {
    vector v1 {10};
    println("v1 = {}", v1);
    println("v1.size() = {}", v1.size());
    println("v1.capacity() = {}", v1.capacity());
    
    // Pointer p1 wijst naar het eerste element van v1
    auto* p1 {&v1[0]};
    // Reference r1 wijst naar het eerste element van v1
    auto& r1 {v1[0]};
    // Iterator i1 wijst naar het eerste element van v1
    auto i1 {v1.cbegin()};
    // Voeg element aan v1 toe
    v1.push_back(42);
    // v1 wordt nu vergroot maar ook verplaatst
    println("v1 = {}", v1);
    println("v1.size() = {}", v1.size());
    println("v1.capacity() = {}", v1.capacity());
    if (p1 != &v1[0])
        println("Oops p1 wijst niet meer naar v1[0]");
    if (r1 != v1[0])
        println("Oops r1 refereert niet meer naar v1[0]");
    if (i1 != v1.cbegin())
        println("Oops i1 wijst niet meer naar v1.cbegin()");
    
    // Dit kunnen we voorkomen door eerst reserve aan te roepen.    
    vector v2 {10};
    println("v2 = {}", v2);
    println("v2.size() = {}", v2.size());
    println("v2.capacity() = {}", v2.capacity());
    v2.reserve(32); // reserveer minstens 32 elementen
    println("v2.capacity() = {}", v2.capacity());

    // Pointer p2 wijst naar het eerste element van v2
    auto* p2 {&v2[0]};
    // Reference r2 wijst naar het eerste element van v2
    auto& r2 {v2[0]};
    // Iterator i2 wijst naar het eerste element van v2
    auto i2 {v2.cbegin()};
    // Voeg element aan v1 toe
    v2.push_back(42);
    // v2 wordt nu vergroot maar niet verplaatst
    println("v2 = {}", v2);
    println("v2.size() = {}", v2.size());
    println("v2.capacity() = {}", v2.capacity());
    if (p2 == &v2[0])
        println("p2 wijst nog steeds naar v2[0]");
    if (p2 == &v2[0])
        println("p2 wijst nog steeds naar v2[0]");
    if (r2 == v2[0])
        println("r2 refereert nog steeds naar v2[0]");
    if (i2 == v2.cbegin())
        println("i2 wijst nog steeds naar v2.cbegin()");
}
