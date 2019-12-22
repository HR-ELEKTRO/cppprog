#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test(int i): waarde{i} {
        cout << "Test object met waarde " << waarde << " aangemaakt.\n";
    }
    ~Test() {
        cout << "Test object met waarde " << waarde << " verwijderd.\n";
    }
    bool is_waarde(int i) const {
        return waarde == i;
    }
private:
    int waarde;
};

void f0() {
    Test t{1};
    if (t.is_waarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Als je dit ziet, dan klopt er iets niet\n";
}

void f1() {
    Test* p{new Test{1}};
    if (p->is_waarde(1)) {
        cout << "Test object heeft waarde 1\n";
        return;
    }
    cout << "Als je dit ziet, dan klopt er iets niet\n";
    delete p;
}

void f2() {
    unique_ptr<Test> p{new Test{2}};
    if (p->is_waarde(2)) {
        cout << "Test object heeft waarde 2\n";
        return;
    }
    cout << "Als je dit ziet, dan klopt er iets niet\n";
}

int main() {
    f0();
    f1();
    f2();
}
