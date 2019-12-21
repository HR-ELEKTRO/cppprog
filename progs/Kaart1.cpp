// Een oplossing m.b.v. een ADT ... wel herbruikbaar en aanpasbaar maar niet uitbreidbaar!

#include <iostream>

using namespace std;

enum CardType {AD178, NI323};

class ADCCard {
public:
    ADCCard(CardType name);
    void selectChannel(int channel);
    int getChannel() const;
    void setAmplifier(double factor);
    double read() const;
private:
    CardType type;
    double amplifyingFactor;
    int selectedChannel;
    int sample() const;
};

ADCCard::ADCCard(CardType name): type{name}, amplifyingFactor{1.0}, selectedChannel{1} {
    // ... eventueel voor alle kaarten benodigde code
    switch (type) {
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

void ADCCard::selectChannel(int channel) {
    selectedChannel = channel;
    // ... eventueel voor alle kaarten benodigde code
    switch (type) {
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

int ADCCard::getChannel() const {
    return selectedChannel;
}

void ADCCard::setAmplifier(double factor) {
    amplifyingFactor = factor;
    // ... eventueel voor alle kaarten benodigde code
    switch (type) {
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

int ADCCard::sample() const {
    int sample;
    // ... eventueel voor alle kaarten benodigde code
    switch (type) {
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

double ADCCard::read() const {
    return sample() * amplifyingFactor / 6553.5;
}

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);

    ADCCard k1{AD178};
    k1.setAmplifier(10);
    k1.selectChannel(3);
    cout << "Kanaal " << k1.getChannel() << " van kaart k1 = " << k1.read() << " V.\n";

    ADCCard k2{NI323};
    k2.setAmplifier(5);
    k2.selectChannel(4);
    cout << "Kanaal " << k2.getChannel() << " van kaart k2 = " << k2.read() << " V.\n";
}
