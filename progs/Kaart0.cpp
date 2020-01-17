// Een gestructureerde oplossing ... zo deden we het vroeger!

#include <iostream>

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
            cout << "AD178 is geinitialiseeerd.\n";
            break;
        case NI323:
            // ... de specifieke voor de NI323 benodigde code
            cout << "NI323 is geinitialiseeerd.\n";
            break;
    }
}

void select_channel(ADCCard& card, int channel) {
    card.selected_channel = channel;
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

int get_channel(const ADCCard& card) {
    return card.selected_channel;
}

void set_amplifier(ADCCard& card, double factor) {
    card.amplifying_factor = factor;
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
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    
    ADCCard c1;
    init_card(c1, AD178);
    set_amplifier(c1, 10);
    select_channel(c1, 3);
    cout << "Kanaal " << get_channel(c1) << " van kaart c1 = " << read_card(c1) << " V.\n";
    
    ADCCard c2;
    init_card(c2, NI323);
    set_amplifier(c2, 5);
    select_channel(c2, 4);
    cout << "Kanaal " << get_channel(c2) << " van kaart c2 = " << read_card(c2) << " V.\n";
}
