import std;
using namespace std;
using namespace std::placeholders;

int main() {
    list l {-3, -4, 3, 4};
    auto r {find_if(l.cbegin(), l.cend(), bind(greater_equal(), _1, 0))};
    if (r != l.cend()) {
        println("Het eerste positieve element is: {}", *r);
    }
}
