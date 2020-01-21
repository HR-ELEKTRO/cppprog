#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
// (a+b)+=c;
//  error: lvalue required as left operand of assignment
    a = ++++b;
//  a = b++++;
//  error: lvalue required as increment operand
    list<int> l {12, 18, 6};
    sort(l.begin(), l.end());

}