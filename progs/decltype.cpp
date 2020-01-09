#include <iostream>
using namespace std;

int main() {
    int rij[] = {12, 2, 17, 32, 1, 18};
    remove_extent_t<decltype(rij)> som {0};
    for (auto element: rij) {
        som += element;
    }
    cout << "som = " << som << '\n';
}

// Als de rij nu als volgt wordt gedefinieerd:
// double rij[] = {12.5, 2, 17, 32, 1, 18};
// dan wordt het type van som en element ook automatisch double