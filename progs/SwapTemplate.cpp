// Template functie swap

#include <iostream>
#ifdef _MSC_VER
// With Microsoft Visual C++ we can not use 'using namespace std' 
// because that compiler tries to invoke std::swap and is confused
using std::cin;
using std::cout;
using std::endl;
#else
using namespace std;
#endif

template <typename T> void swap(T& p, T& q) {
    T t(p);
    p = q;
    q = t;
}

int main() {
    int n(2);
    int m(3);
    cout << "n = " << n << " m = " << m << endl;
    swap(n, m);
    cout << "n = " << n << " m = " << m << endl;
    double x(2.2);
    double y(3.3);
    cout << "x = " << x << " y = " << y << endl;
    swap(x, y);
    cout << "x = " << x << " y = " << y << endl;
    cin.get();
    return 0;
}
