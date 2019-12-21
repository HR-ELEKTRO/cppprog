// Gebruik twee stacks voor een infix calculator

#include <iostream>
#include <cctype>
#include "stacklist.h"
using namespace std;

bool hasLowerPrio(char op1, char op2) {
    return op1 == '+' && op2 == '*';
}

void processOperator(StackWithList<char>& s1, StackWithList<int>& s2) {
    int op2 = s2.top(); s2.pop();
    int op1 = s2.top(); s2.pop();
    switch (s1.top()) {
        case '*': s2.push(op1 * op2); break;
        case '+': s2.push(op1 + op2); break;
    }
    s1.pop();
}

int main() {
    StackWithList<char> s1;
    StackWithList<int> s2;
    char c;
    cout << "Type een infix expressie (met + en * operator) en sluit af met =\n";
    cin >> c;
    while (c != '=') {
        if (isdigit(c)) {
            cin.putback(c);
            int i;
            cin >> i;
            s2.push(i);
        }
        else if (c == '(') {
            s1.push(c);
        }
        else if (c == '+' || c == '*') {
            while (!s1.empty() && s1.top() != '(' && !hasLowerPrio(s1.top(), c)) {
                processOperator(s1, s2);
            }
            s1.push(c);
        }
        else if (c == ')') {
            while (s1.top() != '(') {
                processOperator(s1, s2);
            }
            s1.pop();
        }
        else {
            cout << "Syntax error\n";
        }
        cin >> c;
    }
    while (!s1.empty()) {
        processOperator(s1, s2);
    }
    cout << "= " << s2.top() << '\n';
    s2.pop();
    if (!s2.empty()) {
        cout << "Fout operator ontbreekt.\n";
        s2.pop();
    }
}
