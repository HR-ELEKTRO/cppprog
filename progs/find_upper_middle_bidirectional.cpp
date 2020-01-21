// De functie find_upper_middle_bidirectional geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee bidirectional iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

#include <iostream>
#include <list>
using namespace std;

template <typename I>
I find_upper_middle_bidirectional(I begin, I end) {
    while (begin != end) {
        --end;
        if (begin != end) {
            ++begin;
        }
    }
    return begin;
}

int main() {
    list<int> l1;
    if (find_upper_middle_bidirectional(l1.begin(), l1.end()) != l1.end()) {
        cerr << "Test 1 failed!\n";
        return 1;
    }
    list<int> l2 {1};
    if (*find_upper_middle_bidirectional(l2.begin(), l2.end()) != 1) {
        cerr << "Test 2 failed!\n";
        return 2;
    }
    list<int> l3 {1, 2};
    if (*find_upper_middle_bidirectional(l3.begin(), l3.end()) != 2) {
        cerr << "Test 3 failed!\n";
        return 3;
    }
    list<int> l4 {1, 2, 3};
    if (*find_upper_middle_bidirectional(l4.begin(), l4.end()) != 2) {
        cerr << "Test 4 failed!\n";
        return 4;
    }
    list<int> l5 {1, 2, 3, 4};
    if (*find_upper_middle_bidirectional(l5.begin(), l5.end()) != 3) {
        cerr << "Test 5 failed!\n";
        return 5;
    }
    cerr << "All tests passed!\n";
}