// Een object georienteerde oplossing verdeeld over verschillende files

#include <iostream>

using namespace std;

#include "ad178.h"
#include "ni323.h"
#include "doit.h"

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);
    
    AD178 card1;
    do_it(card1);
    NI323 card2;
    do_it(card2);
}
