#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

#include "MatrixWithIteratoren.h"

int main() {
    using  Matrix = matrix<int, 3, 3>;
    Matrix m1;
//  hele matrix doorlopen
    for (auto& e : m1) {
        e = 0;
    }
    cout << "Alle getallen in matrix m1: \n";
    ostream_iterator<int> iout {cout, " "};
    copy(m1.cbegin(), m1.cend(), iout); cout << '\n';

//  hele matrix doorlopen
    for_each(m1.begin(), m1.end(), [](auto& i){
        i += 1;
    });
    cout << "Alle getallen in matrix m1 met 1 verhoogd: \n";
    copy(m1.cbegin(), m1.cend(), iout); cout << '\n';

    Matrix m2{1, 2, 3, 
              4, 5, 6,
              7, 8, 9};
    cout << "Alle getallen in matrix m2: \n";
    copy(m2.cbegin(), m2.cend(), iout); cout << '\n';

//  bepaalde rij doorlopen
    cout << "Alle getallen in tweede rij van matrix m2: \n";
    copy(m2.crowbegin(1), m2.crowend(1), iout); cout << '\n';
   
//  bepaalde kolom doorlopen
    cout << "Alle getallen in derde kolom van matrix m2: \n";
    copy(m2.ccolumnbegin(2), m2.ccolumnend(2), iout); cout << '\n';

//  alle rijen afdrukken                 
    cout << "Alle getallen in matrix m2 rij voor rij: \n";
    for (Matrix::size_type ri {0}; ri != m2.num_rows(); ++ri) { 
        copy(m2.crowbegin(ri), m2.crowend(ri), iout); cout << '\n';
    }
//  bepaalde kolom optellen bij andere kolom
    cout << "De derde kolom wordt opgeteld bij de eerste kolom.\n";
    transform(m2.ccolumnbegin(2), m2.ccolumnend(2), m2.ccolumnbegin(0), m2.columnbegin(0), plus<int>());
    cout << "Alle getallen in matrix m2 rij voor rij: \n";
    for (Matrix::size_type ri(0); ri != m2.num_rows(); ++ri) { 
        copy(m2.crowbegin(ri), m2.crowend(ri), iout); cout << '\n';
    }
    
//  bepaalde kolom vermenigvuldigen met bepaalde rij
    cout << "De tweede kolom wordt vermenigvuldigd met de tweede rij.\n";
    transform(m2.ccolumnbegin(1), m2.ccolumnend(1), m2.rowbegin(1), m2.columnbegin(1), multiplies<int>());
    cout << "Alle getallen in matrix m2 rij voor rij: \n";
    for (Matrix::size_type ri {0}; ri != m2.num_rows(); ++ri) { 
        copy(m2.crowbegin(ri), m2.crowend(ri), iout); cout << '\n';
    }

// exceptions testen
    try {
    //  Te veel init waarden
        Matrix m2{1, 2, 3, 
                  4, 5, 6,
                  7, 8, 9, 10};
        cout << "Alle getallen in matrix m2: \n";
        copy(m2.cbegin(), m2.cend(), iout); cout << '\n';
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    try {
    //  niet bestaande rij doorlopen
        cout << "Alle getallen in vierde rij van matrix m2: \n";
        copy(m2.crowbegin(3), m2.crowend(3), iout); cout << '\n';
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
    try {
    //  niet bestaande kolom doorlopen
        cout << "Alle getallen in vijfde kolom van matrix m2: \n";
        copy(m2.ccolumnbegin(4), m2.ccolumnend(4), iout); cout << '\n';
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
}