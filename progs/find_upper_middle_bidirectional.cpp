// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee bidirectional iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.

import std;
using namespace std;

template <bidirectional_iterator I>
I find_upper_middle(I begin, I end) {
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
    if (find_upper_middle(l1.begin(), l1.end()) != l1.end()) {
        println(cerr, "Test 1 failed!");
        return 1;
    }
    list l2 {1};
    if (*find_upper_middle(l2.begin(), l2.end()) != 1) {
        println(cerr, "Test 2 failed!");
        return 2;
    }
    list l3 {1, 2};
    if (*find_upper_middle(l3.begin(), l3.end()) != 2) {
        println(cerr, "Test 3 failed!");
        return 3;
    }
    list l4 {1, 2, 3};
    if (*find_upper_middle(l4.begin(), l4.end()) != 2) {
        println(cerr, "Test 4 failed!");
        return 4;
    }
    list l5 {1, 2, 3, 4};
    if (*find_upper_middle(l5.begin(), l5.end()) != 3) {
        println(cerr, "Test 5 failed!");
        return 5;
    }
    println("All tests passed!");
    // forward_list l {12, 18, 6};
    // println("{}", *find_upper_middle(l.begin(), l.end()));
    // find_upper_middle_bidirectional.cpp: In function 'int main()':
    // find_upper_middle_bidirectional.cpp:51:37: error: no matching function for call to 'find_upper_middle(std::forward_list<int>::iterator, std::forward_list<int>::iterator)'
    //    51 |     println("{}", *find_upper_middle(l.begin(), l.end()));
    //       |                    ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
    // find_upper_middle_bidirectional.cpp:51:37: note: there is 1 candidate
    // find_upper_middle_bidirectional.cpp:12:3: note: candidate 1: 'template<class I>  requires  bidirectional_iterator<I> I find_upper_middle(I, I)'
    //    12 | I find_upper_middle(I begin, I end) {
    //       |   ^~~~~~~~~~~~~~~~~
    // find_upper_middle_bidirectional.cpp:12:3: note: template argument deduction/substitution failed:
    // find_upper_middle_bidirectional.cpp:12:3: note: constraints not satisfied
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/concepts: In substitution of 'template<class I>  requires  bidirectional_iterator<I> I find_upper_middle(I, I) [with I = std::_Fwd_list_iterator<int>]':
    // find_upper_middle_bidirectional.cpp:51:37:   required from here
    //    51 |     println("{}", *find_upper_middle(l.begin(), l.end()));
    //       |                    ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/concepts:76:13:   required for the satisfaction of 'derived_from<typename std::__detail::__iter_concept_impl<_Iter>::type, std::bidirectional_iterator_tag>' [with _Iter = std::_Fwd_list_iterator<int>]
    // /usr/lib/gcc/x86_64-pc-cygwin/15.2.0/include/c++/bits/iterator_concepts.h:709:13:   required for the satisfaction of 'bidirectional_iterator<I>' [with I = std::_Fwd_list_iterator<int>]
    // cc1plus: note:   'std::bidirectional_iterator_tag' is not a base of 'std::forward_iterator_tag'
}