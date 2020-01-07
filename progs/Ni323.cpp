#include <iostream>
#include <iomanip>
using namespace std;

#include "ni323.h"

NI323::NI323() {
    // ... de specifieke voor de NI323 benodigde code
    cout << "NI323 is geinitialiseeerd.\n";
}
void NI323::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Kanaal " << channel << " van NI323 is geselecteerd.\n";
}
void NI323::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Versterkingsfactor van NI323 is " << factor << ".\n";
}
int NI323::sample() const {
    // ... de specifieke voor de NI323 benodigde code
    return -0x8000; // -5 * f V
}

