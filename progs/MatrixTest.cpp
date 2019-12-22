#include <iostream>
#include <algorithm>
using namespace std;

#include "Matrix.h"

int main() {
    using Matrix = matrix<int, 2, 3>;
    using Index = Matrix::size_type;
    Matrix m;
    for (auto& e : m) {
        e = 0;
    }
    for (Index row = 0; row < m.num_rows(); ++row) {
        for (Index column = 0; column < m.num_cols(); ++column) {
            cout << m(row, column) << " ";
        }
        cout << '\n';
    }
    for (auto i = m.begin(); i != m.end(); ++i) {
        cout << *i << " ";
    }
    cout << '\n';
    for_each(m.begin(), m.end(), [](int& i){
        i += 1;
    });
    for_each(m.begin(), m.end(), [](const int& i){
        cout << i << " ";
    });
    cout << '\n';
    for_each(m.cbegin(), m.cend(), [](const int& i){
        cout << i << " ";
    });
    cout << '\n';

    const Matrix cm{m};
    for_each(cm.begin(), cm.end(), [](const int& i){
        cout << i << " ";
    });
    cout << '\n';
//  Should give compiler error!
//  for_each(cm.begin(), cm.end(), [](int& i){
//      i += 1;
//  });

    Matrix m2{1, 2, 3, 
              4, 5, 6};
    for (auto e : m2) {
        cout << e << " ";
    }
    cout << '\n';

//  Should give compiler error!
//  Matrix m3{{1, 2, 3, 
//             4, 5, 6, 7}};

    Matrix m4{1, 2, 3, 
              4, 5, 6};

    try {
        Matrix m5{1, 2, 3, 
                  4, 5, 6, 7};
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }        
}