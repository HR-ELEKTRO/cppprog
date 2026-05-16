import std;
using namespace std;

int main() {
    int i {5};
    auto result { i <=> 5 };
    if (result < 0) { println("less"); }
    if (result > 0) { println("greater"); }
    if (result == 0) { println("equal"); }
    result = i <=> 0;
    if (result == strong_ordering::less) { println("less"); }
    if (result == strong_ordering::greater) { println("greater"); }
    if (result == strong_ordering::equal) { println("equal"); }
}
