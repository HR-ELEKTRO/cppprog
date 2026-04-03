// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.
// Afhankelijk van het soort iterator wordt de meest efficiente implementatie
// gekozen (tijdens compile time).

import std;
using namespace std;

template <forward_iterator I>
I find_upper_middle(I begin, I end) {
    println("forward iterator used");
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

template <bidirectional_iterator I>
I find_upper_middle(I begin, I end) {
    println("bidirectional iterator used");
    while (begin != end) {
        --end;
        if (begin != end) {
            ++begin;
        }
    }
    return begin;
}

template <random_access_iterator I>
I find_upper_middle(I begin, I end) {
    println("random access iterator used");
    return begin + (end - begin)/2;
}

int main() {
    forward_list fl {1, 2};
    println("find_upper_middle called on forward_list");
    if (*find_upper_middle(fl.begin(), fl.end()) != 2) {
        println(cerr, "Test 1 failed!");
        return 1;
    }
    list l {1, 2, 3};
    println("find_upper_middle called on list");
    if (*find_upper_middle(l.begin(), l.end()) != 2) {
        println(cerr, "Test 2 failed!");
        return 2;
    }
    vector v {1, 2, 3, 4};
    println("find_upper_middle called on vector");
    if (*find_upper_middle(v.begin(), v.end()) != 3) {
        println(cerr, "Test 3 failed!");
        return 3;
    }
    println("All tests passed!");
}