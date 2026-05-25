import std;
using namespace std;

template<typename T>
concept Printable = requires(T t) { print("{}", t); };

void my_print() {
}

template<Printable T>
void my_print(T head) {
    print("{}", head);
}

template<Printable T, Printable... Tail>
void my_print(T head, Tail... tail) {
    print("{}, ", head); // first, what we do for the head
    my_print(tail...); // then, what we do for the tail
}

int main() {
    my_print("dit is een test: ");
    my_print(1, 2.5, "hello", 'x', vector{1, 2, 3});
}

/* Output:
dit is een test: 1, 2.5, hello, x, [1, 2, 3]
*/
