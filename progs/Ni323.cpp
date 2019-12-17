#include <iostream>
#include <iomanip>
using namespace std;

#include "ni323.h"

NI323::NI323() {
    // ... de specifieke voor de NI323 benodigde code
    cout << "NI323 is geinitialiseeerd." << endl;
}
void NI323::selectChannel(int channel) {
    rememberChannel(channel);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Kanaal " << channel << " van NI323 is geselecteerd." << endl;
}
void NI323::setAmplifier(double factor) {
    rememberAmplifier(factor);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Versterkingsfactor van NI323 is " << factor << "." << endl;
}
int NI323::sample() const {
    // ... de specifieke voor de NI323 benodigde code
    return -0x8000; // -5 * f V
}

