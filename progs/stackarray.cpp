// Een stack geimplementeerd d.m.v. een array

import std;
import stackarray;
using namespace std;

int main() {
    try {
        Stack_with_array<char> s {32};
        char c;
        println("Type een tekst en sluit af met .");
        cin.get(c);
        while (c != '.') {
            s.push(c);
            cin.get(c);
        }
        while (!s.empty()) {
            print("{}", s.top());
            s.pop();
        }
    } catch (const exception& e) {
        println(cerr, "Error: {}", e.what());
    }
}
