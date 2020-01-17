#include <iostream>
using namespace std;

int main() {
    int a, b, c;
// (a+b)+=c;
//  error: lvalue required as left operand of assignment
    a = ++++b;
//  a = b++++;
//  error: lvalue required as increment operand
}