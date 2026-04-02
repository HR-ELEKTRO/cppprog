// Gebruik een stack voor een postfix calculator

import std;
import stacklist;
using namespace std;

int main() {
    Stack_with_list<int> s;
    char c;
    println("Type een postfix expressie (met + en * operator) en sluit af met =");
    cin >> c;
    while (c != '=') {
        if (isdigit(c)) {
            cin.putback(c);
            int i;
            cin >> i;
            s.push(i);
        }
        else if (c == '+') {
            int op2 {s.top()}; s.pop();
            int op1 {s.top()}; s.pop();
            s.push(op1 + op2);
        }
        else if (c == '*') {
            int op2 {s.top()}; s.pop();
            int op1 {s.top()}; s.pop();
            s.push(op1 * op2);
        }
        else {
            println("Syntax error");
        }
        cin >> c;
    }
    println("= {}", s.top());
    s.pop();
    if (!s.empty()) {
        println("Fout operator ontbreekt.");
    }
}
