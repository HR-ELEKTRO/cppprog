import std;
using namespace std;

constexpr unsigned int power(unsigned int n, unsigned int m) {
    unsigned int result = 1;
    for (unsigned int i {0}; i < m; ++i) {
        result *= n;
    }
    return result;
}

int main() {
    println("3 tot de macht 5 = {}", power(3, 5));

    array<int, power(3, 5)> rij;
    
    constexpr unsigned int c1 = power(3, 5);
    println("3 tot de macht 5 = {}", c1);

    unsigned int a, b;
    print("Geef een integer: ");
    cin >> a;
    print("Geef nog een integer: ");
    cin >> b;
    
    println("{} tot de macht {} = {}", a, b, power(a, b));
}
