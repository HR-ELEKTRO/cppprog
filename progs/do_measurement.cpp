#include <iostream>
#include <iomanip>
using namespace std;

#include "do_measurement.h"

void do_measurement(ADCCard& card, double factor, int channel) {
    card.set_amplifier(factor);
    card.select_channel(channel);
    cout << "Kanaal " << card.get_channel() << " = " << card.read() << " V.\n";
}
