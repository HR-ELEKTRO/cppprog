#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int somEven = 0;
    for_each(v.cbegin(), v.cend(), [&somEven](int i) {
        if (i % 2 == 0) {
            somEven += i;
        }
    });
    cout << "Som van alle even getallen in v = " << somEven << endl;
    cin.get();
    return 0;
}