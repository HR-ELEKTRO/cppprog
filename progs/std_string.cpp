#include <iostream>
#include <string>
using namespace std;

// Met een pointer kun je door een C-string heenlopen en de elementen één voor één benaderen.
// Een C-string is een character array en wordt afgesloten door het character NUL. 
void demo1() {
    char naam[] {"Roy"};
    for (const char* p {naam}; *p != '\0'; ++p) {
        cout << *p << ' ';
    }
    cout << '\n';
}

// Je kunt ook het keyword auto gebruiken om de compiler zelf het type van de pointer te laten bepalen.
void demo2() {
    char naam[] {"Roy"};
    for (const auto* p {naam}; *p != '\0'; ++p) {
        cout << *p << ' ';
    }
    cout << '\n';
}

// Met een iterator kun je door een std::string heenlopen en de elementen één voor één benaderen.
// Met een const_iterator kun je alleen lezen. Met een iterator kun je ook schrijven.
// De memberfunctie begin() geeft een iterator terug naar het eerste element van de string.
// De memberfunctie end() geeft een iterator terug net na het laatste element van de string.
// De memberfunctie cbegin() geeft een const_iterator terug naar het eerste element van de string.
// De memberfunctie cend() geeft een const_iterator terug net na het laatste element van de string.
void demo3() {
    string naam {"Harry"};
    for (string::const_iterator i {naam.cbegin()}; i != naam.cend(); ++i) {
        cout << *i << ' ';
    }
    cout << '\n';
}

// Je kunt ook het keyword auto gebruiken om de compiler zelf het type van de iterator te laten bepalen.
void demo4() {
    string naam {"Harry"};
    for (auto i {naam.cbegin()}; i != naam.cend(); ++i) {
        cout << *i << ' ';
    }
    cout << '\n';
}

int main() {
    demo1();
    demo2();
    demo3();
    demo4();
}
