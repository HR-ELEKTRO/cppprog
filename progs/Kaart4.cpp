// Een nieuwe kaart toevoegen: het bewijs voor uitbreidbaarheid

#include <iostream>

using namespace std;

#include "Ad178.h"
#include "Ni323.h"
#include "Bb647.h" // new!e d
#include "do_measurement.h"

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);

    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
    BB647 card3;   // new!
    do_measurement(card3, 2, 7);
}
