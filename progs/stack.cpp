#include <iostream>
#include <cassert>
#include "stacklist.h"
#include "stackarray.h"
using namespace std;

int main() {
    try {
        Stack<char>* s {nullptr};

        cout << "Welke stack wil je gebruiken (l = list, a = array): ";
        char c;
        do {
            cin.get(c);
            if (c == 'l' || c == 'L') {
                s = new Stack_with_list<char>;
            }
            else if (c == 'a' || c == 'A') {
                cout << "Hoeveel elementen wil je gebruiken: ";
                int i;
                cin >> i;
                s = new Stack_with_array<char>(i);
            }
        } while (s == nullptr);

        cout << "Type een tekst en sluit af met .\n";
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
    } catch (const exception& e) {
        cerr << e.what();
    }
}
