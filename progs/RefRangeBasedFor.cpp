#include <iostream>
using namespace std;

int main() {
    int array[] = {12, 2, 17, 32, 1, 18};
    auto som = 0;
    for (auto element: array) {
        som += element;
    }
    cout << "som = " << som << endl;

    for (auto& element: array) {
        element = 0;
    }

    som = 0;
    for (auto element: array) {
        som += element;
    }
    cout << "som = " << som << endl;

    cin.get();
}
