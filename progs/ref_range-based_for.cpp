#include <iostream>
using namespace std;

int main() {
    int rij[] = {12, 2, 17, 32, 1, 18};
    int som {0};
    for (auto element: rij) {
        som += element;
    }
    cout << "som = " << som << '\n';

    for (auto& element: rij) {
        element = 0;
    }

    som = 0;
    for (auto element: rij) {
        som += element;
    }
    cout << "som = " << som << '\n';
}
