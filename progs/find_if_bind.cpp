#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main() {
    list<int> l = {-3, -4, 3, 4};
    list<int>::const_iterator r = find_if(l.cbegin(), l.cend(), bind(greater_equal<int>(), _1, 0));
    if (r != l.cend()) {
        cout << "Het eerste positieve element is: " << *r << endl;
    }
    cin.get();
    return 0;
}
