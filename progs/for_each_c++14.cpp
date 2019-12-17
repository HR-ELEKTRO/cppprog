#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {-3, -4, 3, 4};
    ostream_iterator<int> iout(cout, " ");
    copy(v.cbegin(), v.cend(), iout);
    cout << endl;

//  Bewerking opgeven met een lambda functie.
//  Gebruik auto als parametertype (werkt niet voor C++11, wel voor C++14).
    for_each(v.cbegin(), v.cend(), [](auto i) {
        cout << i << " " << i << " ";
    });
    cout << endl;
    
    cin.get();
    return 0;
}
