#include <iostream>
#include <cstdint>
using namespace std;

// Dit programma zet een c-string om naar een int64_t.
// Dit slaat inderdaad nergens op maar laat wel zien hoe we compiler kunnen dwingen om zoiets toch te doen
// door middel van een zogenaamde type cast

int main() {
    
    int64_t i;
//  i = "Hallo";
//  Error: invalid conversion from ‘const char*’ to ‘int64_t’
    i = (int64_t)"Hello"; // oude C syntax
    cout << i << '\n';
    i = int64_t("Bello"); // oude C++ syntax
    cout << i << '\n';
    i = reinterpret_cast<int64_t>("Bella"); // nieuwe C++ syntax
    cout << i << '\n';
}

/* Output:
4299173889
4299173895
4299173901
*/
