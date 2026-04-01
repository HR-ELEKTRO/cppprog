// Een gestructureerde oplossing ... zo deden we het vroeger!

import std;
using namespace std;

enum Card_type {AD178, NI323};

struct ADCCard {
    Card_type type;
    double amplifying_factor;
    int selected_channel;
};

void init_card(ADCCard& card, Card_type type) {
    card.type = type;
    card.amplifying_factor = 1.0;
    card.selected_channel = 1;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
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

void select_channel(ADCCard& card, int channel) {
    card.selected_channel = channel;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
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

int get_channel(const ADCCard& card) {
    return card.selected_channel;
}

void set_amplifier(ADCCard& card, double factor) {
    card.amplifying_factor = factor;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
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

int sample_card(const ADCCard& card) {
    int sample;
    // ... eventueel voor alle kaarten benodigde code
    switch (card.type) {
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

double read_card(const ADCCard& card) {
    return sample_card(card) * card.amplifying_factor / 6553.5;
}

int main() {
    ADCCard c1;
    init_card(c1, AD178);
    set_amplifier(c1, 10);
    select_channel(c1, 3);
    println("Kanaal {} van kaart c1 = {:.2f} V.", get_channel(c1), read_card(c1));
    
    ADCCard c2;
    init_card(c2, NI323);
    set_amplifier(c2, 5);
    select_channel(c2, 4);
    println("Kanaal {} van kaart c2 = {:.2f} V.", get_channel(c2), read_card(c2));
}
