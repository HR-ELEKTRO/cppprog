import std;
using namespace std;

// move p n elements forward
template<forward_iterator Iter>
void advance(Iter& p, int n) {
    while (n--)
        ++p; // a forward iterator has ++, but not + or +=
}

template<random_access_iterator Iter>
void advance(Iter& p, int n) {
    p += n; // a random-access iterator has +=
}

int main() {
    vector v {1, 2, 3, 4, 5};
    auto p = v.begin();
    advance(p, 3);
    println("*p = {}", *p);
    list l {1, 2, 3, 4, 5};
    auto q = l.begin();
    advance(q, 3);
    println("*q = {}", *q);
}