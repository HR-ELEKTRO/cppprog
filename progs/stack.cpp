import std;
import stacklist;
import stackarray;
using namespace std;

int main() {
    try {
        unique_ptr<Stack<char>> s {nullptr};

        print("Welke stack wil je gebruiken (l = list, a = array): ");
        char c;
        do {
            cin.get(c);
            if (c == 'l' || c == 'L') {
                s = move(make_unique<Stack_with_list<char>>());
            }
            else if (c == 'a' || c == 'A') {
                print("Hoeveel elementen wil je gebruiken: ");
                int i;
                cin >> i;
                s = move(make_unique<Stack_with_array<char>>(i));
            }
        } while (s == nullptr);

        println("Type een tekst en sluit af met .");
        cin.get(c);
        while (c != '.') {
            s->push(c);
            cin.get(c);
        }
        while (!s->empty()) {
            print("{}", s->top());
            s->pop();
        }
    } catch (const exception& e) {
        println(cerr, "Error: {}", e.what());
    }
}
