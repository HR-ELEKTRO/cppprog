#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print_vector(const vector<T> v) {
    for (const auto& e: v) 
        cout << e << ' ';
    cout << '\n';
}
    
int main() {
    vector<int> v1{10};
    print_vector(v1);
    vector<int> v2(10);
    print_vector(v2);
    
    cout << "v1.capacity() = " << v1.capacity() << '\n';
    cout << "v2.capacity() = " << v2.capacity() << '\n';
    
    // Pointer en Iterator wijzen naar elementen van v1
    int* p1 = &v1[0];
    // Voeg element aan v1 toe
    auto i1 = v1.cbegin();
    v1.push_back(42);
    // v2 wordt nu vergroot maar ook verplaatst
    cout << "v1.capacity() = " << v1.capacity() << '\n';
    if (p1 != &v1[2])
        cout << "Oops p1 wijst niet meer naar v1[0]\n";
    if (i1 != v1.cbegin())
        cout << "Oops i1 wijst niet meer naar v1.cbegin()\n";
    
    // Dit kunnen we voorkomen door eerst reserve aan te roepen.
    v2.reserve(32); // reserveer minstens 32 elementen
    cout << "v2.capacity() = " << v2.capacity() << '\n';
    
    int* p2 = &v2[0];
    // Voeg element aan v2 toe
    auto i2 = v2.cbegin();
    v2.push_back(42);
    cout << "v2.capacity() = " << v2.capacity() << '\n';
    if (p2 == &v2[0])
        cout << "p2 wijst nog steeds naar v2[0]\n";
    if (i2 == v2.cbegin())
        cout << "i2 wijst nog steeds naar v2.cbegin()\n";
}
