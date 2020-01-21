#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "De som van alle getallen in v = " << accumulate(v.cbegin(), v.cend(), 0) << '\n';
    cout << "De som van alle even getallen in v = " << accumulate(v.cbegin(), v.cend(), 0, [](int som_tot_nu_toe, int elm) {
        return elm % 2 == 0 ? som_tot_nu_toe + elm : som_tot_nu_toe;
    }) << '\n';
}