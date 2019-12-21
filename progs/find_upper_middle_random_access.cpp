// De functie find_upper_middle_random_access geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee random access iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

#include <iostream>
#include <vector>
using namespace std;

template <typename I>
I find_upper_middle_random_access(I begin, I end) {
    return begin + (end - begin)/2;
}

int main() {
    vector<int> v1;
    if (find_upper_middle_random_access(v1.begin(), v1.end()) != v1.end()) {
        cerr << "Test 1 failed!\n";
        return 1;
    }
    vector<int> v2{1};
    if (*find_upper_middle_random_access(v2.begin(), v2.end()) != 1) {
        cerr << "Test 2 failed!\n";
        return 2;
    }
    vector<int> v3{1, 2};
    if (*find_upper_middle_random_access(v3.begin(), v3.end()) != 2) {
        cerr << "Test 3 failed!\n";
        return 3;
    }
    vector<int> v4{1, 2, 3};
    if (*find_upper_middle_random_access(v4.begin(), v4.end()) != 2) {
        cerr << "Test 4 failed!\n";
        return 4;
    }
    vector<int> v5{1, 2, 3, 4};
    if (*find_upper_middle_random_access(v5.begin(), v5.end()) != 3) {
        cerr << "Test 5 failed!\n";
        return 5;
    }
    cerr << "All tests passed!\n";
}