import std;
using namespace std;

int main() {
    // definieer array van 15 integers
    array<int, 15> a;
    // vul met kwadraten
    int i {0};
    for (auto& e: a) {
        e = i * i;
        ++i;
    }
    // druk af
    println("{}", a);

    // kopiëren van de een array
    auto b {a};
    println("{}", b);
    // vergelijken van arrays
    if (a != b) {
        println("Dit kan niet waar zijn!");
    }
    try {
        a.at(100) = 12;
        // ongeldige index ==> foutmelding (exception)
    } catch(const out_of_range& e) {
        println(cerr, "Error: {}", e.what());
    }
    a[i] = 12;
    // ongeldige index ==> Abort in debug mode, ongedefinieerd gedrag in release mode
}

/* Uitvoer:
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196]
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196]
Error: array::at: __n (which is 100) >= _Nm (which is 15)
/usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/array:210: constexpr std::array<_Tp, _Nm>::value_type& std::array<_Tp, _Nm>::operator[](size_type) [with _Tp = int; long unsigned int _Nm = 15; reference = int&; size_type = long unsigned int]: Assertion '__n < this->size()' failed.
Aborted
*/
