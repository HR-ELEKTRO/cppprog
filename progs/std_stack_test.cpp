#include <iostream>
#include <list>
#include <stack>
using namespace std;

int main() {
    stack<char, list<char>> s;
    cout << "Type een tekst en sluit af met .\n";
    char c;
    cin.get(c);
    while (c != '.') {
        s.push(c);
        cin.get(c);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
