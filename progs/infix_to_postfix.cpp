// Gebruik een stack voor een infix naar postfix converter

import std;
import stacklist;
using namespace std;

bool has_lower_prio(char op1, char op2) {
    // geeft true als prio(op1) < prio(op2)
    // eenvoudig omdat alleen + en * toegestaan zijn
    return op1 == '+' && op2 == '*';
}

int main() {
    Stack_with_list<char> s;
    char c;
    println("Type een infix expressie (met + en * operator) en sluit af met =");
    cin >> c;
    while (c != '=') {
        if (isdigit(c)) {
            cin.putback(c);
            int i;
            cin >> i;
            println("{} ", i);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == '+' || c == '*') {
            while (!s.empty() && s.top() != '(' && !has_lower_prio(s.top(), c)) {
                println("{} ", s.top());
                s.pop();
            }
            s.push(c);
        }
        else if (c == ')') {
            while (s.top() != '(') {
                println("{} ", s.top());
                s.pop();
            }
            s.pop();
        }
        else {
            println("Syntax error");
        }
        cin >> c;
    }
    while (!s.empty()) {
        println("{} ", s.top());
        s.pop();
    }
}
