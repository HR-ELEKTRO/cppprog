#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    list<int> priem {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    ifstream getallen {"getallen_gesorteerd.txt"};
    if (!getallen)
        return 1; 
    auto eerste_priem {find_first_of(istream_iterator<int> {getallen}, istream_iterator<int> {}, priem.begin(), priem.end())};
    if (eerste_priem != istream_iterator<int> {}) {
        cout << "Het eerste priemgetal kleiner dan 100 is: " << *eerste_priem << '\n';
    } 
}
