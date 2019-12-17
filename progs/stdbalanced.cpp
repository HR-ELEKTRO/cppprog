// Controleer op gebalanceerde haakjes. Algoritme wordt
// besproken in de les. Invoer afsluiten met een punt.

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    char c;
    cout << "Type een expressie met haakjes () [] of {} en sluit af met ." << endl;
    cin.get(c);
    while (c != '.') {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else {
            if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) {
                    cout << "Fout " << c << " bijbehorend haakje openen ontbreekt." << endl;
                }
                else {
                    char d = s.top();
                    s.pop();
                    if (d == '(' && c != ')' || d == '{' && c != '}' || d == '[' && c != ']') {
                        cout << "Fout " << c << " bijbehorend haakje openen ontbreekt." << endl;
                    }
                }
            }
        }
        cin.get(c);
    }
    while (!s.empty()) {
        char d = s.top();
        s.pop();
        cout << "Fout " << d << " bijbehorend haakje sluiten ontbreekt." << endl;
    }
    cin.get();
    cin.get();
    return 0;
}
