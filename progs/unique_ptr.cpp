import std;
using namespace std;

class Test {
public:
    Test(int i): waarde{i} {
        println("Test object met waarde {} aangemaakt.", waarde);
    }
    ~Test() {
        println("Test object met waarde {} verwijderd.", waarde);
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
        println("Test object heeft waarde 0");
        return;
    }
    println("Test object heeft waarde ongelijk aan 0");
}

void f1(int i) {
    Test* p {new Test{i}};
    if (p->is_waarde(0)) {
        println("Test object heeft waarde 0");
        return;
    }
    println("Test object heeft waarde ongelijk aan 0");
    delete p;
}

void f2(int i) {
    unique_ptr<Test> p {new Test {i}};
    if (p->is_waarde(0)) {
        println("Test object heeft waarde 0");
        return;
    }
    println("Test object heeft waarde ongelijk aan 0");
}

void f3(int i) {
    auto p {make_unique<Test>(i)};
    if (p->is_waarde(0)) {
        println("Test object heeft waarde 0");
        return;
    }
    println("Test object heeft waarde ongelijk aan 0");
}

int main() {
    f0(0);
    f1(0); // OOPS memory leak
    f2(0);
    f3(0);
}
