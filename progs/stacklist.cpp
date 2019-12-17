// Een stack geimplementeerd d.m.v. een list

#include <iostream>
#include "stacklist.h"
using namespace std;

int main() {
    StackWithList<char> s;
    char c;
    cout << "Type een tekst en sluit af met ." << endl;
    cin.get(c);
    while (c != '.') {
        s.push(c);
        cin.get(c);
    }
    // Probeer een stack te kopiëren:
    // StackWithList<char> t(s);
    // GCC4.8 error: use of deleted function 'StackWithList<char>::StackWithList(const StackWithList<char>&)'
    // VS2013 error: 'Stack<T>::Stack(const Stack<T> &)' : attempting to reference a deleted function
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cin.get();
    cin.get();
    return 0;
}
