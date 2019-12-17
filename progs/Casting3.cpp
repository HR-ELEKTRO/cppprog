#include <iostream>
#include <string>
using namespace std;

void stiekem(const string& a) {
    const_cast<string&>(a) = "Hallo";
}

int main() {
    string s("Dag");
    cout << "s = " << s << endl;
    stiekem(s);
    cout << "s = " << s << endl;
//  ...
    cin.get();
    return 0;
}

/*
Output:

s = Dag
s = Hallo
*/
