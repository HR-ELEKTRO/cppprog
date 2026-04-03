import std;
#include <cassert>
using namespace std;

int max(const vector<int>& v) {
    vector<int>::size_type n = v.size();
    assert(n > 0);
    int max = v[0];
    for (vector<int>::size_type i = 1; i < n; ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int main() {
    vector v = {12, 2, 17, 32, 1, 18};
    println("max = {}", max(v));
}