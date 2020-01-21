#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;

int main() {
    list<double> resultaten {0.4, 1.4, 1.5, 4.9, 5.0, 8.9, 9.1, 9.5, 10.0};
    vector<int> gehele_resultaten;
    // Alle resultaten < 1.5 moeten worden afgerond tot 1
    // Alle overige resultaten moeten worden afgerond
    transform(resultaten.cbegin(), resultaten.cend(), back_inserter(gehele_resultaten), [](double r) -> int {
        if (r < 1.5) {
            return 1;
        }
        return round(r);
    });
    for (auto r: gehele_resultaten) {
        cout << r << " ";
    }
    cout << '\n';
}
