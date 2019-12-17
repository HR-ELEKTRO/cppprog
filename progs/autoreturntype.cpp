#include <iostream>
#include <algorithm>
using namespace std;

auto max3(int i1, int i2, int i3) {
    return max(max(i1, i2), i3);
}

int main() {
    cout << "max3(12, 18, 17) = " << max3(12, 18, 17);

    cin.get();
    return 0;
}