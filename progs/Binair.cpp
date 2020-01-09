#include <iostream>
using namespace std;

int main() {
    {
        int i {023};
        cout << "i = " << i << '\n';
    }
    {
        int i {0x23};
        cout << "i = " << i << '\n';
    }
    {
        int i {0b10111101};
        cout << "i = " << i << '\n';
    }
}