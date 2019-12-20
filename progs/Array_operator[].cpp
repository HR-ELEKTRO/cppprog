// operator[] moet twee maal gedefinieerd worden

#include <iostream>
#include <cassert>
using namespace std;

/*
    overloaden van operator[] ...

    je moet altijd twee memberfuncties definieren zodat de operator[] werkt 
    met const objecten en ook met non-const objecten:

    T& operator[](int);              // called for non-const object
    const T& operator[](int) const;  // called for const object

    Array5  is niet correct
    Array6	is niet correct
    Array10 is wel correct
*/

class Array5 {
public:
    Array5();
    int& operator[](int index) const;
private:
    int data[5];
};

Array5::Array5() {
    for (int i = 0; i < 5; ++i)
        data[i] = 0;
}

int& Array5::operator[](int index) const {
    assert(index >= 0 && index < 5);
//  return data[index];
//  Error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
//  De compiler herkend de fout!
//  We kunnen daar wel om heen werken, maar dan kun je ook in een const
//  Array5 schrijven en dat is niet de bedoeling:
    return (int&)(data[index]);
}

class Array6 {
public:
    Array6();
    int& operator[](int index);
private:
    int data[6];
};

Array6::Array6() {
    for (int i = 0; i < 6; ++i)
        data[i] = 0;
}

int& Array6::operator[](int index) {
    assert(index >= 0 && index < 6);
    return data[index];
}

class Array10 {
public:
    Array10();
    int& operator[](int index);
    const int& operator[](int index) const;
private:
    int data[10];
};

Array10::Array10() {
    for (int i = 0; i < 10; ++i)
        data[i] = 0;
}

int& Array10::operator[](int index) {
    assert(index >= 0 && index < 10);
    return data[index];
}

const int& Array10::operator[](int index) const {
    assert(index >= 0 && index < 10);
    return data[index];
}

int main() {
    Array5 v5;
    for (int i = 0; i < 5; ++i)
        v5[i] = i;
    const Array5 w5{v5};
    w5[0] = 5;
//  Schrijven in een const Array moet niet mogen maar mag hier wel!
    for (int i = 0; i < 5; ++i)
        cout << v5[i];
    cout << '\n';
    for (int i = 0; i < 5; ++i)
        cout << w5[i];
    cout << '\n';

    Array6 v6;
    for (int j = 0; j < 6; ++j)
        v6[j] = j;
    const Array6 w6{v6};
//  w6[0] = 6;
//  Error: passing ‘const Array6’ as ‘this’ argument discards qualifiers
    for (int j = 0; j < 6; ++j)
        cout << v6[j];
    cout << '\n';
//  for (int j = 0; j < 6; ++j)
//      cout << w6[j];
//  Error: passing ‘const Array6’ as ‘this’ argument discards qualifiers
    cout << '\n';

    Array10 v10;
    for (int k = 0; k < 10; ++k)
        v10[k] = k;
    const Array10 w10{v10};
//  w10[0] = 10;
//  Error: assignment of read-only location ‘w10.Array10::operator[](0)’
    for (int k = 0; k < 10; ++k)
        cout << v10[k];
    cout << '\n';
    for (int k = 0; k < 10; ++k)
        cout << w10[k];
    cout << '\n';
}
