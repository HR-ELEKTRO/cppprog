#include <iostream>
using namespace std;

int main() {
    int i = 4.6;
    cout << "i = " << i << '\n';
    // int j {4.6};
    // error: narrowing conversion of ‘4.5999999999999996e+0’ from ‘double’ to ‘int’
}