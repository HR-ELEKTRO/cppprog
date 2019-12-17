#include <iostream>
#include <iomanip>
using namespace std;

#include "ad178.h"

AD178::AD178() {
    // ... de specifieke voor de AD178 benodigde code
    cout << "AD178 is geinitialiseeerd." << endl;
}
void AD178::selectChannel(int channel) {
    rememberChannel(channel);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Kanaal " << channel << " van AD178 is geselecteerd." << endl;
}
void AD178::setAmplifier(double factor) {
    rememberAmplifier(factor);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Versterkingsfactor van AD178 is " << factor << "." << endl;
}
int AD178::sample() const {
    // ... de specifieke voor de AD178 benodigde code
    return 0x7FFF; // +5 * f V
}

