#include <iostream>
#include <iomanip>
using namespace std;

#include "adccard.h"

ADCCard::ADCCard(): amplifyingFactor(1.0), selectedChannel(1) {
    // voor alle kaarten benodigde code
    cout << "initialisatie is gestart.\n";
}
int ADCCard::getChannel() const {
    return selectedChannel;
}
double ADCCard::read() const {
    return sample() * amplifyingFactor / 6553.5;
}
void ADCCard::rememberChannel(int channel) {
    selectedChannel = channel;
}
void ADCCard::rememberAmplifier(double factor) {
    amplifyingFactor = factor;
}
