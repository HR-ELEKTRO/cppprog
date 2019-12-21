// Gebruik een stack voor een infix naar postfix converter

#include <iostream>
#include <cctype>
#include "stacklist.h"
using namespace std;

bool hasLowerPrio(char op1, char op2) {
    // geeft true als prio(op1) < prio(op2)
    // eenvoudig omdat alleen + en * toegestaan zijn
    return op1 == '+' && op2 == '*';
}

int main() {
    StackWithList<char> s;
    char c;
    cout << "Type een infix expressie (met + en * operator) en sluit af met =\n";
    cin >> c;
    while (c != '=') {
        if (isdigit(c)) {
            cin.putback(c);
            int i;
            cin >> i;
            cout << i << " ";
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == '+' || c == '*') {
            while (!s.empty() && s.top() != '(' && !hasLowerPrio(s.top(), c)) {
                cout << s.top() << " ";
                s.pop();
            }
            s.push(c);
        }
        else if (c == ')') {
            while (s.top() != '(') {
                cout << s.top() << " ";
                s.pop();
            }
            s.pop();
        }
        else {
            cout << "Syntax error\n";
        }
        cin >> c;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
