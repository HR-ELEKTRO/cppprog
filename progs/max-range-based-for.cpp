import std;
#include <cassert>
using namespace std;

int max(const vector<int>& v) {
    assert(v.size() > 0);
    auto max = v[0];
    for (auto elm : v) {
        if (elm > max) {
            max = elm;
        }
    }
    return max;
}

int main() {
    vector v = {12, 2, 17, 32, 1, 18};
    println("max = {}", max(v));
}