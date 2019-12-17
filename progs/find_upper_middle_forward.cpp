// De functie find_upper_middle_forward geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee forward iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

#include <iostream>
#include <forward_list>
using namespace std;

template <typename I>
I find_upper_middle_forward(I begin, I end) {
    I i = begin;
    while (begin != end) {
        ++begin;
        if (begin != end) {
            ++begin;
            ++i;
        }
    }
    return i;
}

int main() {
    forward_list<int> l1;
    if (find_upper_middle_forward(l1.begin(), l1.end()) != l1.end()) {
        cerr << "Test 1 failed!" << endl;
        return 1;
    }
    forward_list<int> l2 = {1};
    if (*find_upper_middle_forward(l2.begin(), l2.end()) != 1) {
        cerr << "Test 2 failed!" << endl;
        return 2;
    }
    forward_list<int> l3 = {1, 2};
    if (*find_upper_middle_forward(l3.begin(), l3.end()) != 2) {
        cerr << "Test 3 failed!" << endl;
        return 3;
    }
    forward_list<int> l4 = {1, 2, 3};
    if (*find_upper_middle_forward(l4.begin(), l4.end()) != 2) {
        cerr << "Test 4 failed!" << endl;
        return 4;
    }
    forward_list<int> l5 = {1, 2, 3, 4};
    if (*find_upper_middle_forward(l5.begin(), l5.end()) != 3) {
        cerr << "Test 5 failed!" << endl;
        return 5;
    }
    return 0;
}