// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee random access iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

import std;
using namespace std;

template <random_access_iterator I>
I find_upper_middle(I begin, I end) {
    return begin + (end - begin)/2;
}

int main() {
    vector<int> v1;
    if (find_upper_middle(v1.begin(), v1.end()) != v1.end()) {
        println(cerr, "Test 1 failed!");
        return 1;
    }
    vector v2 {1};
    if (*find_upper_middle(v2.begin(), v2.end()) != 1) {
        println(cerr, "Test 2 failed!");
        return 2;
    }
    vector v3 {1, 2};
    if (*find_upper_middle(v3.begin(), v3.end()) != 2) {
        println(cerr, "Test 3 failed!");
        return 3;
    }
    vector v4 {1, 2, 3};
    if (*find_upper_middle(v4.begin(), v4.end()) != 2) {
        println(cerr, "Test 4 failed!");
        return 4;
    }
    vector v5 {1, 2, 3, 4};
    if (*find_upper_middle(v5.begin(), v5.end()) != 3) {
        println(cerr, "Test 5 failed!");
        return 5;
    }
    println("All tests passed!");
    // list l = {12, 18, 6};
    // println("{}", *find_upper_middle(l.begin(), l.end()));
    // find_upper_middle_random_access.cpp: In function 'int main()':
    // find_upper_middle_random_access.cpp:44:37: error: no matching function for call to 'find_upper_middle(std::__cxx11::list<int>::iterator, std::__cxx11::list<int>::iterator)'
    //    44 |     println("{}", *find_upper_middle(l.begin(), l.end()));
    //       |                    ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
    // find_upper_middle_random_access.cpp:44:37: note: there is 1 candidate
    // find_upper_middle_random_access.cpp:12:3: note: candidate 1: 'template<class I>  requires  random_access_iterator<I> I find_upper_middle(I, I)'
    //    12 | I find_upper_middle(I begin, I end) {
    //       |   ^~~~~~~~~~~~~~~~~
    // find_upper_middle_random_access.cpp:12:3: note: template argument deduction/substitution failed:
    // find_upper_middle_random_access.cpp:12:3: note: constraints not satisfied
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/concepts: In substitution of 'template<class I>  requires  random_access_iterator<I> I find_upper_middle(I, I) [with I = std::_List_iterator<int>]':    
    // find_upper_middle_random_access.cpp:44:37:   required from here
    //    44 |     println("{}", *find_upper_middle(l.begin(), l.end()));
    //       |                    ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/concepts:76:13:   required for the satisfaction of 'derived_from<typename std::__detail::__iter_concept_impl<_Iter>::type, std::random_access_iterator_tag>' [with _Iter = std::_List_iterator<int>]
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/iterator_concepts.h:719:13:   required for the satisfaction of 'random_access_iterator<I>' [with I = std::_List_iterator<int>]
    // cc1plus: note:   'std::random_access_iterator_tag' is not a base of 'std::bidirectional_iterator_tag'
}