#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <execution>
using namespace std;

int main() {
    {
        vector<int> rij {1, 7, 2, 5, 8, 3};
        sort(rij.begin(), rij.end());
        ostream_iterator<int> iout {cout, " "};
        copy(rij.begin(), rij.end(), iout);
    }
    {
        vector<int> rij {1, 7, 2, 5, 8, 3};
        sort(execution::seq, rij.begin(), rij.end());
        ostream_iterator<int> iout {cout, " "};
        copy(rij.begin(), rij.end(), iout);
    }
    {
        vector<int> rij {1, 7, 2, 5, 8, 3};
        sort(execution::par, rij.begin(), rij.end());
        ostream_iterator<int> iout {cout, " "};
        copy(rij.begin(), rij.end(), iout);
    }
    {
        vector<int> rij {1, 7, 2, 5, 8, 3};
        sort(execution::par_unseq, rij.begin(), rij.end());
        ostream_iterator<int> iout {cout, " "};
        copy(rij.begin(), rij.end(), iout);
    }
}
