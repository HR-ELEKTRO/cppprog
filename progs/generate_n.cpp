#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> kwadraten;
    int n {0};
    generate_n(back_inserter(kwadraten), 10, [&n]() {
        ++n; return n * n;
    }); 
    copy(kwadraten.begin(), kwadraten.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';
}