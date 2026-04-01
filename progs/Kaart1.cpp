// Een oplossing m.b.v. een UDT ... wel herbruikbaar en aanpasbaar maar niet uitbreidbaar!

import std;
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
            println("AD178 is geinitialiseeerd.");
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            println("NI323 is geinitialiseeerd.");
            break;
    }
}

void ADCCard::select_channel(int channel) {
    selected_channel = channel;
    // ... eventueel voor alle kaarten benodigde code
    switch (type) {
        case AD178:
            // ... de specifieke voor de AD178 benodigde code
            println("Kanaal {} van AD178 is geselecteerd.", channel);
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            println("Kanaal {} van NI323 is geselecteerd.", channel);
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
            println("Versterkingsfactor van AD178 is {:.2f}.", factor);
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            println("Versterkingsfactor van NI323 is {:.2f}.", factor);
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
    ADCCard k1 {AD178};
    k1.set_amplifier(10);
    k1.select_channel(3);
    println("Kanaal {} van kaart k1 = {:.2f} V.", k1.get_channel(), k1.read());

    ADCCard k2 {NI323};
    k2.set_amplifier(5);
    k2.select_channel(4);
    println("Kanaal {} van kaart k2 = {:.2f} V.", k2.get_channel(), k2.read());
}
