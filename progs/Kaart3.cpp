// Een object georienteerde oplossing verdeeld over verschillende files

#include <iostream>

using namespace std;

#include "Ad178.h"
#include "Ni323.h"
#include "do_measurement.h"

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);
    
    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
}
