// Gebruik een stack voor een postfix calculator

#include <iostream>
#include <cctype>
#include "stacklist.h"
using namespace std;

int main() {
    StackWithList<int> s;
    char c;
    cout << "Type een postfix expressie (met + en * operator) en sluit af met =\n";
    cin >> c;
    while (c != '=') {
        if (isdigit(c)) {
            cin.putback(c);
            int i;
            cin >> i;
            s.push(i);
        }
        else if (c == '+') {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(op1 + op2);
        }
        else if (c == '*') {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(op1 * op2);
        }
        else {
            cout << "Syntax error\n";
        }
        cin >> c;
    }
    cout << "= " << s.top() << '\n';
    s.pop();
    if (!s.empty()) {
        cout << "Fout operator ontbreekt.\n";
    }
}
