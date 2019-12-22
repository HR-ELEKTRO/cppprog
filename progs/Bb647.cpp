#include <iostream>
#include <iomanip>
using namespace std;

#include "bb647.h"

BB647::BB647() {
    // ... de specifieke voor de BB647 benodigde code
    cout << "BB647 is geinitialiseeerd.\n";
}
void BB647::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de BB647 benodigde code
    cout << "Kanaal " << channel << " van BB647 is geselecteerd.\n";
}
void BB647::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de BB647 benodigde code
    cout << "Versterkingsfactor van BB647 is " << factor << ".\n";
}
int BB647::sample() const {
    // ... de specifieke voor de BB647 benodigde code
    return 0x4000; // 2.5 * f V
}

