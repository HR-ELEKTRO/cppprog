import std;
using namespace std;

// Dit programma zet een c-string om naar een int64_t.
// Dit slaat inderdaad nergens op maar laat wel zien hoe we compiler kunnen
// dwingen om zoiets toch te doen door middel van een zogenaamde type cast

int main() {
    int64_t i;
//  i = "Hallo";
//  Error: invalid conversion from ‘const char*’ to ‘int64_t’
    i = (int64_t)"Hello"; // oude C syntax
    println("{}", i);
    i = int64_t("Bello"); // oude C++ syntax
    println("{}", i);
    i = reinterpret_cast<int64_t>("Bella"); // nieuwe C++ syntax
    println("{}", i);
}

/* Output:
4299277297
4299277306
4299277312
*/
