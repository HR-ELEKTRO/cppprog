// Gebruik een stack voor het controleren van de haakjes
// Invoer afsluiten met .

import std;
import stacklist;
using namespace std;

int main() {
    Stack_with_list<char> s;
    char c;
    println("Type een expressie met haakjes () [] of {{}} en sluit af met .");
    cin.get(c);
    while (c != '.') {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else {
            if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) {
                    println("Fout {} bijbehorend haakje openen ontbreekt.", c);
                }
                else {
                    char d {s.top()};
                    s.pop();
                    if ((d == '(' && c != ')') || (d == '{' && c != '}') || (d == '[' && c != ']')) {
                        println("Fout {} bijbehorend haakje openen ontbreekt.", c);
                    }
                }
            }
        }
        cin.get(c);
    }
    while (!s.empty()) {
        char d {s.top()};
        s.pop();
        println("Fout {} bijbehorend haakje sluiten ontbreekt.", d);
    }
}
