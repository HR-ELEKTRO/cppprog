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

void f0(int i) {
    Test t {i};
    if (t.is_waarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Test object heeft waarde ongelijk aan 0\n";
}

void f1(int i) {
    Test* p {new Test{i}};
    if (p->is_waarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Test object heeft waarde ongelijk aan 0\n";
    delete p;
}

void f2(int i) {
    unique_ptr<Test> p {new Test {i}};
    if (p->is_waarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Test object heeft waarde ongelijk aan 0\n";
}

void f3(int i) {
    auto p {make_unique<Test>(i)};
    if (p->is_waarde(0)) {
        cout << "Test object heeft waarde 0\n";
        return;
    }
    cout << "Test object heeft waarde ongelijk aan 0\n";
}

int main() {
    f0(0);
    f1(0); // OOPS memory leak
    f2(0);
    f3(0);
}
