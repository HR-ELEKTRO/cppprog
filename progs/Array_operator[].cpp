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
    for (int i(0); i < 5; ++i)
        data[i] = 0;
}

int& Array5::operator[](int index) const {
    assert(index < 5);
//  return data[index];
//  [C++ Error (Microsoft)]: 'return' : cannot convert from 'const int' to 'int &' (Conversion loses qualifiers)
//  [C++ Error (GCC)]:       invalid initialization of reference of type 'int &' from expression of type 'const int'
//  de compiler herkend de fout!
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
    for (int i(0); i < 6; ++i)
        data[i] = 0;
}

int& Array6::operator[](int index) {
    assert(index < 6);
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
    for (int i(0); i < 10; ++i)
        data[i] = 0;
}

int& Array10::operator[](int index) {
    assert(index < 10);
    return data[index];
}

const int& Array10::operator[](int index) const {
    assert(index < 10);
    return data[index];
}

int main() {
    Array5 v5;
    for (int i(0); i < 5; ++i)
        v5[i] = i;
    const Array5 w5(v5);
    w5[0] = 5;
//  Schrijven in een const Array moet niet mogen maar mag hier wel!
    for (int i(0); i < 5; ++i)
        cout << v5[i];
    cout << endl;
    for (int i(0); i < 5; ++i)
        cout << w5[i];
    cout << endl;

    Array6 v6;
    for (int j(0); j < 6; ++j)
        v6[j] = j;
    const Array6 w6(v6);
//  w6[0] = 6;
//  Redelijke foutmelding:
//  [C++ Error (Microsoft)]: binary '[' : no operator found which takes a left-hand operand of type 'const Array6' (or there is no acceptable conversion)
//  Beste foutmelding:
//  [C++ Error (GCC)]:       no match for 'operator[]' in 'w6[0]'
    for (int j(0); j < 6; ++j)
        cout << v6[j];
    cout << endl;
//  for (int j(0); j < 6; ++j)
//      cout << w6[j];
//  Redelijke foutmelding:
//  [C++ Error (Microsoft)]: binary '[' : no operator found which takes a left-hand operand of type 'const Array6' (or there is no acceptable conversion)
//  Beste foutmelding:
//  [C++ Error (GCC)]:       no match for 'operator[]' in 'w6[j]'
    cout << endl;

    Array10 v10;
    for (int k(0); k < 10; ++k)
        v10[k] = k;
    const Array10 w10(v10);
//  w10[0] = 10;
//  [C++ Error (Microsoft)]: 'w10' : you cannot assign to a variable that is const
//  [C++ Error (GCC)]:       assignment of read-only location
    for (int k(0); k < 10; ++k)
        cout << v10[k];
    cout << endl;
    for (int k(0); k < 10; ++k)
        cout << w10[k];
    cout << endl;

    cin.get();
    return 0;
}
