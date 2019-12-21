// Een stack geimplementeerd d.m.v. een array

#include <iostream>
#include "stackarray.h"
using namespace std;

int main() {
    StackWithArray<char> s{32};
    char c;
    cout << "Type een tekst en sluit af met .\n";
    cin.get(c);
    while (c != '.') {
        s.push(c);
        cin.get(c);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
