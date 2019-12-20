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
    bool isWaarde(int i) const {
        return waarde == i;
    }
private:
    int waarde;
};

void f0() {
    Test t{1};
    if (t.isWaarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Als je dit ziet, dan klopt er iets niet\n";
}

void f1() {
    Test* p{new Test{1}};
    if (p->isWaarde(1)) {
        cout << "Test object heeft waarde 1\n";
        return;
    }
    cout << "Als je dit ziet, dan klopt er iets niet\n";
    delete p;
}

void f2() {
    unique_ptr<Test> p{new Test{2}};
    if (p->isWaarde(2)) {
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
