// Een stack geimplementeerd d.m.v. een list

#include <iostream>
#include "stacklist.h"
using namespace std;

int main() {
    StackWithList<char> s;
    char c;
    cout << "Type een tekst en sluit af met .\n";
    cin.get(c);
    while (c != '.') {
        s.push(c);
        cin.get(c);
    }
//  Probeer een stack te kopiëren:
//  StackWithList<char> t{s};
//  Error: use of deleted function ‘StackWithList<char>::StackWithList(const StackWithList<char>&)’
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
