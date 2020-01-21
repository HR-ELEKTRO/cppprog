// Gebruik een stack voor het controleren van de haakjes
// Invoer afsluiten met .

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    char c;
    cout << "Type een expressie met haakjes () [] of {} en sluit af met .\n";
    cin.get(c);
    while (c != '.') {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else {
            if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) {
                    cout << "Fout " << c << " bijbehorend haakje openen ontbreekt.\n";
                }
                else {
                    char d {s.top()};
                    s.pop();
                    if ((d == '(' && c != ')') || (d == '{' && c != '}') || (d == '[' && c != ']')) {
                        cout << "Fout " << c << " bijbehorend haakje openen ontbreekt.\n";
                    }
                }
            }
        }
        cin.get(c);
    }
    while (!s.empty()) {
        char d {s.top()};
        s.pop();
        cout << "Fout " << d << " bijbehorend haakje sluiten ontbreekt.\n";
    }
}
