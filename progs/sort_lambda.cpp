#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> rij;
    ifstream fin {"getallen_ongesorteerd.txt"};
    if (!fin)
        return 1; // kan fin niet openen
    istream_iterator<int> iin {fin}, einde;
    copy(iin, einde, back_inserter(rij));
    sort(rij.begin(), rij.end(), [](auto i, auto j) {
        return i > j;
    });
    ofstream fout {"getallen_gesorteerd.txt"};
    if (!fout)
        return 2; // kan fout niet openen
    ostream_iterator<int> iout {fout, " "};
    copy(rij.begin(), rij.end(), iout);
}
