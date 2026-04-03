// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee forward iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

import std;
using namespace std;

template <forward_iterator I>
I find_upper_middle(I begin, I end) {
    I i {begin};
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
    if (find_upper_middle(l1.begin(), l1.end()) != l1.end()) {
        println(cerr, "Test 1 failed!");
        return 1;
    }
    forward_list l2 {1};
    if (*find_upper_middle(l2.begin(), l2.end()) != 1) {
        println(cerr, "Test 2 failed!");
        return 2;
    }
    forward_list l3 {1, 2};
    if (*find_upper_middle(l3.begin(), l3.end()) != 2) {
        println(cerr, "Test 3 failed!");
        return 3;
    }
    forward_list l4 {1, 2, 3};
    if (*find_upper_middle(l4.begin(), l4.end()) != 2) {
        println(cerr, "Test 4 failed!");
        return 4;
    }
    forward_list l5 {1, 2, 3, 4};
    if (*find_upper_middle(l5.begin(), l5.end()) != 3) {
        println(cerr, "Test 5 failed!");
        return 5;
    }
    println("All tests passed!");
}