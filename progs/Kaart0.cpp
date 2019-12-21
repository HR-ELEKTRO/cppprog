// Een gestructureerde oplossing ... zo deden we het vroeger!

#include <iostream>

using namespace std;

enum CardType {AD178, NI323};

struct ADCCard {
    CardType type;
    double amplifyingFactor;
    int selectedChannel;
};

void initCard(ADCCard& card, CardType type) {
    card.type = type;
    card.amplifyingFactor = 1.0;
    card.selectedChannel = 1;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
        case AD178:
            // ... de specifieke voor de AD178 benodigde code
            cout << "AD178 is geinitialiseeerd.\n";
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            cout << "NI323 is geinitialiseeerd.\n";
            break;
    }
}

void selectChannel(ADCCard& card, int channel) {
    card.selectedChannel = channel;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
        case AD178:
            // ... de specifieke voor de AD178 benodigde code
            cout << "Kanaal " << channel << " van AD178 is geselecteerd.\n";
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            cout << "Kanaal " << channel << " van NI323 is geselecteerd.\n";
            break;
    }
}

int getChannel(const ADCCard& card) {
    return card.selectedChannel;
}

void setAmplifier(ADCCard& card, double factor) {
    card.amplifyingFactor = factor;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
        case AD178:
            // ... de specifieke voor de AD178 benodigde code
            cout << "Versterkingsfactor van AD178 is " << factor << ".\n";
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            cout << "Versterkingsfactor van NI323 is " << factor << ".\n";
            break;
        }
}

int sampleCard(const ADCCard& card) {
    int sample;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
        case AD178:
            // ... de specifieke voor de AD178 benodigde code
            sample = 0x7FFF; // +5 * amplifyingFactor V
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            sample = -0x8000; // -5 * amplifyingFactor V
            break;
    }
    return sample;
}

double readCard(const ADCCard& card) {
    return sampleCard(card) * card.amplifyingFactor / 6553.5;
}

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);
    
    ADCCard c1;
    initCard(c1, AD178);
    setAmplifier(c1, 10);
    selectChannel(c1, 3);
    cout << "Kanaal " << getChannel(c1) << " van kaart c1 = " << readCard(c1) << " V.\n";
    
    ADCCard c2;
    initCard(c2, NI323);
    setAmplifier(c2, 5);
    selectChannel(c2, 4);
    cout << "Kanaal " << getChannel(c2) << " van kaart c2 = " << readCard(c2) << " V.\n";
}
