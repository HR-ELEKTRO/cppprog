import std;
import hr.brojz.Matrix;
using namespace std;

int main() {
    using Matrix = matrix<int, 2, 3>;
    using Index = Matrix::size_type;
    Matrix m;
    for (auto& e : m) {
        e = 0;
    }
    for (Index row {0}; row < m.num_rows(); ++row) {
        for (Index column {0}; column < m.num_cols(); ++column) {
            print("{} ", m(row, column));
        }
        println();
    }
    for (auto i = m.begin(); i != m.end(); ++i) {
        print("{} ", *i);
    }
    println();
    for_each(m.begin(), m.end(), [](auto& i){
        i += 1;
    });
    for_each(m.begin(), m.end(), [](const auto& i){
        print("{} ", i);
    });
    println();
    for_each(m.cbegin(), m.cend(), [](const auto& i){
        print("{} ", i);
    });
    println();

    const Matrix cm {m};
    for_each(cm.begin(), cm.end(), [](const auto& i){
        print("{} ", i);
    });
    println();
//  Should give compiler error!
//  for_each(cm.begin(), cm.end(), [](auto& i){
//      i += 1;
//  });

    Matrix m2 {1, 2, 3, 
               4, 5, 6};
    for (auto e : m2) {
        print("{} ", e);
    }
    println();

//  Should give compiler error!
//  Matrix m3 {{1, 2, 3, 
//              4, 5, 6, 7}};

    try {
        Matrix m4 {1, 2, 3, 
                   4, 5, 6, 7};
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }        
}