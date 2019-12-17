// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.
// Afhankelijk van het soort iterator wordt de meest efficiente implementatie
// gekozen (tijdens compile time).

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
using namespace std;

template <typename I>
I find_upper_middle(I begin, I end, forward_iterator_tag dummy) {
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

template <typename I>
I find_upper_middle(I begin, I end, bidirectional_iterator_tag dummy) {
    while (begin != end) {
        --end;
        if (begin != end) {
            ++begin;
        }
    }
    return begin;
}

template <typename I>
I find_upper_middle(I begin, I end, random_access_iterator_tag dummy) {
    return begin + (end - begin)/2;
}

template <typename I>
I find_upper_middle(I begin, I end) {
    return find_upper_middle(begin, end, typename iterator_traits<I>::iterator_category());
}

int main() {
    forward_list<int> fl = {1, 2};
    if (*find_upper_middle(fl.begin(), fl.end()) != 2) {
        cerr << "Test 1 failed!" << endl;
        return 1;
    }
    list<int> l = {1, 2, 3};
    if (*find_upper_middle(l.begin(), l.end()) != 2) {
        cerr << "Test 2 failed!" << endl;
        return 2;
    }
    vector<int> v = {1, 2, 3, 4};
    if (*find_upper_middle(v.begin(), v.end()) != 3) {
        cerr << "Test 3 failed!" << endl;
        return 3;
    }
    return 0;
}