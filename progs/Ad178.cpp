#include <iostream>
#include <iomanip>
using namespace std;

#include "Ad178.h"

AD178::AD178() {
    // ... de specifieke voor de AD178 benodigde code
    cout << "AD178 is geinitialiseeerd.\n";
}
void AD178::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Kanaal " << channel << " van AD178 is geselecteerd.\n";
}
void AD178::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Versterkingsfactor van AD178 is " << factor << ".\n";
}
int AD178::sample() const {
    // ... de specifieke voor de AD178 benodigde code
    return 0x7FFF; // +5 * f V
}
