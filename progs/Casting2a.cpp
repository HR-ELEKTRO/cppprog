import std;
using namespace std;

int main() {
    int i1 {1};
    int i2 {2};
    // double d {i1 / i2};
    // error: narrowing conversion of '(i1 / i2)' from 'int' to 'double'
    // println("d = {}", d);
    double e {static_cast<double>(i1) / i2};
    println("e = {}", e);
}

/* Output:
e = 0.5
*/
