import std;
import stacklist;
import stackarray;
using namespace std;

int main() {
    try {
        Stack<char>* s {nullptr};

        print("Welke stack wil je gebruiken (l = list, a = array): ");
        char c;
        do {
            cin.get(c);
            if (c == 'l' || c == 'L') {
                s = new Stack_with_list<char>;
            }
            else if (c == 'a' || c == 'A') {
                print("Hoeveel elementen wil je gebruiken: ");
                int i;
                cin >> i;
                s = new Stack_with_array<char>(i);
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
        delete s;
    } catch (const exception& e) {
        println(cerr, "Error: {}", e.what());
    }
}
