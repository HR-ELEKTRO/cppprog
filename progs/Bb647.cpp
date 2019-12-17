#include <iostream>
#include <iomanip>
using namespace std;

#include "bb647.h"

BB647::BB647() {
    // ... de specifieke voor de BB647 benodigde code
    cout << "BB647 is geinitialiseeerd." << endl;
}
void BB647::selectChannel(int channel) {
    rememberChannel(channel);
    // ... de specifieke voor de BB647 benodigde code
    cout << "Kanaal " << channel << " van BB647 is geselecteerd." << endl;
}
void BB647::setAmplifier(double factor) {
    rememberAmplifier(factor);
    // ... de specifieke voor de BB647 benodigde code
    cout << "Versterkingsfactor van BB647 is " << factor << "." << endl;
}
int BB647::sample() const {
    // ... de specifieke voor de BB647 benodigde code
    return 0x4000; // 2.5 * f V
}

