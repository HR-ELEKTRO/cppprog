#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> w;
    for (int i = 0; i < 10; ++i) {
        w.push_back(i * i);
    }
    ostream_iterator<int> out(cout, " ");
    copy(w.cbegin(), w.cend(), out); cout << endl;
        
//  verwijder alle even elementen:
    w.erase(remove_if(w.begin(), w.end(), bind(equal_to<int>(), bind(modulus<int>(), _1, 2), 0)), w.end());
    copy(w.cbegin(), w.cend(), out); cout << endl;

    cin.get();
    return 0;
}
