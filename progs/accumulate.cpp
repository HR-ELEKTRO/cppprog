#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Som van alle getallen in v = " << accumulate(v.cbegin(), v.cend(), 0) << endl;
    cout << "Som van alle even getallen in v = " << accumulate(v.cbegin(), v.cend(), 0, [](int somTotNuToe, int elm) {
        return elm % 2 == 0 ? somTotNuToe + elm : somTotNuToe;
    }) << endl;
    cin.get();
    return 0;
}