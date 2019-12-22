// Een object georienteerde oplossing ... wel HERBRUIKBAAR wel AANPASBAAR wel UITBREIDBAAR

#include <iostream>

using namespace std;

class ADCCard {
public:
    ADCCard();
    virtual ~ADCCard() = default;
    virtual void select_channel(int channel) = 0;
    int get_channel() const;
    virtual void set_amplifier(double factor) = 0;
    double read() const;
protected:
    void remember_channel(int channel);
    void remember_amplifier(double factor);
private:
    double amplifying_factor;
    int selected_channel;
    virtual int sample() const = 0;
};

class AD178: public ADCCard {
public:
    AD178();
    virtual void select_channel(int channel);
    virtual void set_amplifier(double factor);
private:
    virtual int sample() const;
};

class NI323: public ADCCard {
public:
    NI323();
    virtual void select_channel(int channel);
    virtual void set_amplifier(double factor);
private:
    virtual int sample() const;
};

ADCCard::ADCCard(): amplifying_factor{1.0}, selected_channel{1} {
    // ... voor alle kaarten benodigde code
    cout << "initialisatie is gestart.\n";
}
int ADCCard::get_channel() const {
    return selected_channel;
}
double ADCCard::read() const {
    return sample() * amplifying_factor / 6553.5;
}
void ADCCard::remember_channel(int channel) {
    selected_channel = channel;
}
void ADCCard::remember_amplifier(double factor) {
    amplifying_factor = factor;
}

AD178::AD178() {
    // ... de specifieke voor de AD178 benodigde code
    cout << "AD178 is geinitialiseeerd.\n";
}
void AD178::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Kanaal " << channel << " van AD178 is geselecteerd.\n";
}
void AD178::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de AD178 benodigde code
    cout << "Versterkingsfactor van AD178 is " << factor << ".\n";
}
int AD178::sample() const {
    // ... de specifieke voor de AD178 benodigde code
    return 0x7FFF; // +5 * amplifying_factor V
}

NI323::NI323() {
    // ... de specifieke voor de NI323 benodigde code
    cout << "NI323 is geinitialiseeerd.\n";
}
void NI323::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Kanaal " << channel << " van NI323 is geselecteerd.\n";
}
void NI323::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Versterkingsfactor van NI323 is " << factor << ".\n";
}
int NI323::sample() const {
    // ... de specifieke voor de NI323 benodigde code
    return -0x8000; // -5 * amplifying_factor V
}

void do_it(ADCCard& selected_channel) {
    selected_channel.set_amplifier(10);
    selected_channel.select_channel(3);
    cout << "Kanaal " << selected_channel.get_channel() << " = " << selected_channel.read() << " V.\n";
}

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);
    
    AD178 card1;
    do_it(card1);
    NI323 card2;
    do_it(card2);
}
