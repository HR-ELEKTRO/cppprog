// De functie find_upper_middle geeft een iterator terug die 
// wijst naar het midden van de als argument meegegeven range [begin, end).
// De range wordt aangegeven door twee iteratoren.
// Als het aantal elementen in de range even is, dan zijn er twee middelste 
// elementen en dan wordt een iterator naar het tweede middelste (upper) 
// element teruggegeven.
// Afhankelijk van het soort iterator wordt de meest efficiente implementatie
// gekozen (tijdens compile time).

// Kan vanaf C++17 ook (eenvoudiger) geimplementeerd worden met compile time if's.
// Zie find_upper_middle_with_compile_time_if.cpp
// Kan vanaf C++20 ook (nog eenvoudiger) geimplementeerd worden met iterator concepts en overloading op basis van die concepts.
// Zie find_upper_middle.cpp

// In de standaard C++ library is voor elke iteratorsoort een zogenoemd `iterator_tag`
// type gedefinieerd. Er is dus een `random_access_`iterator_tag`` type, een
// `bidirectional_iterator_tag` en een `forward_iterator_tag`. We definiëren nu drie
// overloaded template functies die allemaal `find_upper_middle` heten en behalve de
// twee parameters `begin` en `end` nog een derde parameter hebben genaamd `dummy`.
// Deze `dummy` parameter is van het type van de betreffende `iterator_tag`. Deze
// parameter wordt verder in de implementatie van de functie niet gebruikt.

// Vervolgens wordt er nog een vierde overloaded `find_upper_middle` template functie
// gedefinieerd die slechts twee parameters heeft: `begin` en `end`. Deze functie 
// roept vervolgens één van de andere drie `find_upper_middle` template functies aan
// met als derde argument een bij de iteratoren `begin` en `end` behorende
// `iterator_tag` object. We kunnen de bij een iterator horende `iterator_tag` 
// opvragen met behulp van de standaard `iterator_traits` template class, Zie 
// eventueel http://en.cppreference.com/w/cpp/iterator/iterator_traits.

// Het iterator type moet als template argument aan deze template class worden
// doorgegeven. In deze class is een type gedefinieerd genaamd iterator_category die
// overeenkomt met het betreffende `iterator_tag` type. Dit type kunnen we gebruiken
// om een (dummy) object aan te maken. Het type van dit object (het `iterator_tag`
// type) wordt vervolgens door de compiler gebruikt om de juiste find_upper_middle
// te selecteren.

import std;
using namespace std;

template <typename I>
I find_upper_middle(I begin, I end, forward_iterator_tag /*dummy*/) {
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

template <typename I>
I find_upper_middle(I begin, I end, bidirectional_iterator_tag /*dummy*/) {
    println("bidirectional iterator used");
    while (begin != end) {
        --end;
        if (begin != end) {
            ++begin;
        }
    }
    return begin;
}

template <typename I>
I find_upper_middle(I begin, I end, random_access_iterator_tag /*dummy*/) {
    println("random access iterator used");
    return begin + (end - begin)/2;
}

template <typename I>
I find_upper_middle(I begin, I end) {
    return find_upper_middle(begin, end, typename iterator_traits<I>::iterator_category {});
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