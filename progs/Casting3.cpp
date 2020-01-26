#include <iostream>
#include <string>
using namespace std;

void stiekem(const string& a) {
    const_cast<string&>(a) = "Hallo";
}

int main() {
    string s {"Dag"};
    cout << "s = " << s << '\n';
    stiekem(s);
    cout << "s = " << s << '\n';
}

/* Output:
s = Dag
s = Hallo
*/
