#include <iostream>
using namespace std;

int main() {
    int i1 {1};
    int i2 {2};
    double d {i1 / i2};
    // Error:  warning: narrowing conversion of ‘(i1 / i2)’ from ‘int’ to ‘double’
    cout << "d = " << d << '\n';
    double e{static_cast<double>(i1) / i2};
    cout << "e = " << e << '\n';
}

/* Output:
d = 0
e = 0.5
*/
