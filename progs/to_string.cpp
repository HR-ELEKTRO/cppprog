import std;
using namespace std;

int main() {
    int i = -42;
    unsigned int u = 42;
    long l = -42000000000;
    unsigned long ul = 42000000000;
    long long ll = -4200000000000000000;
    unsigned long long ull = 4200000000000000000;
    float f = numbers::pi;
    double d = numbers::pi;
    long double ld = numbers::pi;
    println("to_string({}) geeft {}", i, to_string(i));
    println("to_string({}) geeft {}", u, to_string(u));
    println("to_string({}) geeft {}", l, to_string(l));
    println("to_string({}) geeft {}", ul, to_string(ul));
    println("to_string({}) geeft {}", ll, to_string(ll));
    println("to_string({}) geeft {}", ull, to_string(ull));
    println("to_string({}) geeft {}", f, to_string(f));
    println("to_string({}) geeft {}", d, to_string(d));
    println("to_string({}) geeft {}", ld, to_string(ld));
}

/* uitvoer:
to_string(-42) geeft -42
to_string(42) geeft 42
to_string(-42000000000) geeft -42000000000
to_string(42000000000) geeft 42000000000
to_string(-4200000000000000000) geeft -4200000000000000000
to_string(4200000000000000000) geeft 4200000000000000000
to_string(3.1415927) geeft 3.141593
to_string(3.141592653589793) geeft 3.141593
to_string(3.141592653589793116) geeft 3.141593
*/