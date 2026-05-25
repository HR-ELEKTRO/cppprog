import std;
using namespace std;

void f1(const char* s) {
    println("f1(const char* s): s = {}", s);
}

void f2(const string& s) {
    println("f2(const string& s): s = {}", s);
}

void f3(const char* s) {
    println("f3(const char* s): s = {}", s);
}

void f3(const string& s) {
    println("f3(const string& s): s = {}", s);
}

void f4(string_view s) {
    println("f4(string_view s): s = {}", s);
}

int main() {
    string hallo {"Hallo daar!"};
    f1("Hallo wereld!");
    /*
    f1(hallo); // error: cannot convert 'std::string' to 'const char*'
    */
    f1(hallo.c_str());
    f2("Hallo wereld!");
    f2(hallo);
    f3("Hallo wereld!");
    f3(hallo);
    f4("Hallo wereld!");
    f4(hallo);
}

/* Output:
f1(const char* s): s = Hallo wereld!
f1(const char* s): s = Hallo daar!
f2(const string& s): s = Hallo wereld!
f2(const string& s): s = Hallo daar!
f3(const char* s): s = Hallo wereld!
f3(const string& s): s = Hallo daar!
f4(string_view s): s = Hallo wereld!
f4(string_view s): s = Hallo daar!
*/