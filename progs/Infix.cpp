// Gebruik twee stacks voor een infix calculator

import std;
import stacklist;
using namespace std;

bool has_lower_prio(char op1, char op2) {
    return op1 == '+' && op2 == '*';
}

void process_operator(Stack_with_list<char>& s1, Stack_with_list<int>& s2) {
    int op2 {s2.top()}; s2.pop();
    int op1 {s2.top()}; s2.pop();
    switch (s1.top()) {
        case '*': s2.push(op1 * op2); break;
        case '+': s2.push(op1 + op2); break;
    }
    s1.pop();
}

int main() {
    Stack_with_list<char> s1;
    Stack_with_list<int> s2;
    char c;
    println("Type een infix expressie (met + en * operator) en sluit af met =");
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
            while (!s1.empty() && s1.top() != '(' && !has_lower_prio(s1.top(), c)) {
                process_operator(s1, s2);
            }
            s1.push(c);
        }
        else if (c == ')') {
            while (s1.top() != '(') {
                process_operator(s1, s2);
            }
            s1.pop();
        }
        else {
            println("Syntax error");
        }
        cin >> c;
    }
    while (!s1.empty()) {
        process_operator(s1, s2);
    }
    println("= {}", s2.top());
    s2.pop();
    if (!s2.empty()) {
        println("Fout operator ontbreekt.");
        s2.pop();
    }
}
