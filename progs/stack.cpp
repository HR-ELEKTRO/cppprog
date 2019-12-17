#include <iostream>
#include <cassert>
#include "stacklist.h"
#include "stackarray.h"
using namespace std;

int main() {
    Stack<char>* s = 0;

    cout << "Welke stack wil je gebruiken (l = list, a = array): ";
    char c;
    do {
        cin.get(c);
        if (c == 'l' || c == 'L') {
            s = new StackWithList<char>;
        }
        else if (c == 'a' || c == 'A') {
            cout << "Hoeveel elementen wil je gebruiken: ";
            int i;
            cin >> i;
            s = new StackWithArray<char>(i);
        }
    } while (s == 0);

    cout << "Type een tekst en sluit af met ." << endl;
    cin.get(c);
    while (c != '.') {
        s->push(c);
        cin.get(c);
    }
    while (!s->empty()) {
        cout << s->top();
        s->pop();
    }
    delete s;

    cin.get();
    cin.get();
    return 0;
}
