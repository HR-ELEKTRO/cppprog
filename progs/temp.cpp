#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 1> a;
    cout << sizeof a << '\n';
    int a2[1];
    cout << sizeof a2 / sizeof a2[0] << '\n';
    
}