#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int max(const vector<int>& v) {
    assert(v.size() > 0);
    auto max = v[0];
    for (decltype(v.size()) i = 1; i < v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int main() {
    vector<int> v = {12, 2, 17, 32, 1, 18};
    cout << "max = " << max(v) << endl;
    cin.get();
}