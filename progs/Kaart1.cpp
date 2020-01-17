// Een oplossing m.b.v. een UDT ... wel herbruikbaar en aanpasbaar maar niet uitbreidbaar!

#include <iostream>

using namespace std;

enum Card_type {AD178, NI323};

class ADCCard {
public:
    ADCCard(Card_type name);
    void select_channel(int channel);
    int get_channel() const;
    void set_amplifier(double factor);
    double read() const;
private:
    Card_type type;
    double amplifying_factor;
    int selected_channel;
    int sample() const;
};

ADCCard::ADCCard(Card_type name): type{name}, amplifying_factor{1.0}, selected_channel{1} {
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

void ADCCard::select_channel(int channel) {
    selected_channel = channel;
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

int ADCCard::get_channel() const {
    return selected_channel;
}

void ADCCard::set_amplifier(double factor) {
    amplifying_factor = factor;
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
            sample = 0x7FFF; // +5 * amplifying_factor V
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            sample = -0x8000; // -5 * amplifying_factor V
            break;
    }
    return sample;
}

double ADCCard::read() const {
    return sample() * amplifying_factor / 6553.5;
}

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);

    ADCCard k1 {AD178};
    k1.set_amplifier(10);
    k1.select_channel(3);
    cout << "Kanaal " << k1.get_channel() << " van kaart k1 = " << k1.read() << " V.\n";

    ADCCard k2 {NI323};
    k2.set_amplifier(5);
    k2.select_channel(4);
    cout << "Kanaal " << k2.get_channel() << " van kaart k2 = " << k2.read() << " V.\n";
}
