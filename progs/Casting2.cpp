#include <iostream>
using namespace std;

int main() {
    int i1 = 1;
    int i2 = 2;
    double d = i1 / i2;
    cout << "d = " << d << endl;
    double e = static_cast<double>(i1) / i2;
    cout << "e = " << e << endl;
    cin.get();
    return 0;
}

/*
Output:

d = 0
e = 0.5
*/
