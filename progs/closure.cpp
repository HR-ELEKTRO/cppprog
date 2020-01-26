#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int som_even {0};
    for_each(v.cbegin(), v.cend(), [&som_even](auto i) {
        if (i % 2 == 0) {
            som_even += i;
        }
    });
    cout << "De som van alle even getallen in v = " << som_even << '\n';
}