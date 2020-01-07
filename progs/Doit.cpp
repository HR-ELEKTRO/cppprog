#include <iostream>
#include <iomanip>
using namespace std;

#include "adccard.h"

void do_it(ADCCard& c) {
    c.set_amplifier(10);
    c.select_channel(3);
    cout << "Kanaal " << c.get_channel() << " = " << c.read() << " V.\n";
}

