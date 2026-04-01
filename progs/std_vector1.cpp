import std;
using namespace std;

int main() {
    // definieer vector van integers
    vector<int> v;
    // vul met kwadraten
    for (int i {0}; i < 15; ++i) {
        v.push_back(i * i);
    }
    // druk af
    println("{}", v);
    
    // kopiëren van een vector
    auto w {v};
    println("{}", w);
    // vergelijken van vectoren
    if (v != w) {
        println("Dit kan niet waar zijn!");
    }
    try {
        v.at(100) = 12;
        // ongeldige index ==> foutmelding (exception)
    } catch(const out_of_range& e) {
        println(cerr, "Error: {}", e.what());
    }
    v[100] = 12;
    // ongeldige index  ==> Abort in debug mode, ongedefinieerd gedrag in release mode
}

/* Uitvoer:
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196]
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196]
Error: vector::_M_range_check: __n (which is 100) >= this->size() (which is 15)
/usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/stl_vector.h:1263: constexpr std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = int; _Alloc = std::allocator<int>; reference = int&; size_type = long unsigned int]: Assertion '__n < this->size()' failed.
Aborted
*/
