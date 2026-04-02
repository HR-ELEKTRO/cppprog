// Een stack geimplementeerd d.m.v. een list

import std;
import stacklist;
using namespace std;

int main() {
    try {
        Stack_with_list<char> s;
        char c;
        println("Type een tekst en sluit af met .");
        cin.get(c);
        while (c != '.') {
            s.push(c);
            cin.get(c);
        }
    //  Probeer een stack te kopiëren:
    //  Stack_with_list<char> t {s};
    //  Error: use of deleted function 'Stack_with_list<char>::Stack_with_list(const Stack_with_list<char>&)'
        while (!s.empty()) {
            print("{}", s.top());
            s.pop();
        }
    } catch (const exception& e) {
        println(cerr, "Error: {}", e.what());
    }
}
