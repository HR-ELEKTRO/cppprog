import std;
using namespace std;

void stiekem(const string& a) {
    const_cast<string&>(a) = "Hallo";
}

int main() {
    string s {"Dag"};
    println("s = {}", s);
    stiekem(s);
    println("s = {}", s);
}

/* Output:
s = Dag
s = Hallo
*/
