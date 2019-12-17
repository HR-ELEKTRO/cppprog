#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
#include "stacklist.h"
using namespace std;

// Deze Calculator class berekent de waarde van een infix expressie
// die bestaat uit integers en operatoren. De volgende operatoren worden
// herkend: ^ (machtsverheffen), *, / ,% (modulo), + en - . ^ heeft de 
// hoogste prioriteit, daarna *, / en % en tot slot + en -. Je kunt 
// haakjes, ( en ), gebruiken om de prioriteit aan te passen.

class Calculator {
public:
    int calculate(const string& s);
private:
    bool hasLowerPrio(char op1, char op2);
    void processOperator();
    StackWithList<char> s1;
    StackWithList<int> s2;
};

int Calculator::calculate(const string& s){
    char c;
    istringstream is(s);
    is >> c;
    while (c != '=') {
        if (isdigit(c)) {
            is.putback(c);
            int i;
            is >> i;
            s2.push(i);
        }
        else if (c == '(') {
            s1.push(c);
        }
        else if (c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-') {
            while (!s1.empty() && s1.top() != '(' && !hasLowerPrio(s1.top(), c)) {
                processOperator();
            }
            s1.push(c);
        }
        else if (c == ')') {
            while (s1.top() != '(') {
                processOperator();
            }
            s1.pop();
        }
        else {
            cout << "Syntax error" << endl;
        }
        is >> c;
    }
    while (!s1.empty()) {
        processOperator();
    }
    int result = s2.top();
    s2.pop();
    if (!s2.empty()) {
        cout << "Fout operator ontbreekt." << endl;
        s2.pop();
    }
    return result;
}

bool Calculator::hasLowerPrio(char op1, char op2) {
    return 
        (op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '%' || op2 == '^') ||
        (op1 == '*' || op1 == '/' || op1 == '%') && (op2 == '^');
}

void Calculator::processOperator() {
    int op2 = s2.top(); s2.pop();
    int op1 = s2.top(); s2.pop();
    switch (s1.top()) {
        case '^': s2.push(static_cast<int>(pow(op1, op2))); break;
        case '*': s2.push(op1 * op2); break;
        case '/': s2.push(op1 / op2); break;
        case '%': s2.push(op1 % op2); break;
        case '+': s2.push(op1 + op2); break;
        case '-': s2.push(op1 - op2); break;
    }
    s1.pop();
}

int main() {
    Calculator c;
    assert(c.calculate("(3 * 4 + (40 / (23 - 7 % 4)) * 2 ^ 1) ^ 2 =") == 256);
    string s;
    do {
        cout << "Type een infix expressie en sluit af met <enter>" << endl;
        getline(cin, s);
        if (!s.empty()) {
            cout << "= " << c.calculate(s + "=") << endl;
        }
    } while (!s.empty());
    return 0;
}
