// Een stack geimplementeerd d.m.v. een list

#include <iostream>
#include "stacklist.h"
using namespace std;

int main() {
    Stack_with_list<char> s;
    char c;
    cout << "Type een tekst en sluit af met .\n";
    cin.get(c);
    while (c != '.') {
        s.push(c);
        cin.get(c);
    }
//  Probeer een stack te kopiëren:
//  Stack_with_list<char> t{s};
//  Error: use of deleted function ‘Stack_with_list<char>::Stack_with_list(const Stack_with_list<char>&)’
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
