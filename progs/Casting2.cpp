import std;
using namespace std;

int main() {
    int i1 {1};
    int i2 {2};
    println("1/2 = {}", i1 / i2);
    println("1/2 = {}", static_cast<double>(i1) / i2);
}

/* Output:
1/2 = 0
1/2 = 0.5
*/
