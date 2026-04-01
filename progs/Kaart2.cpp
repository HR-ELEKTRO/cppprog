// Een object georienteerde oplossing ... wel HERBRUIKBAAR wel AANPASBAAR wel UITBREIDBAAR

import std;
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
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};

class NI323: public ADCCard {
public:
    NI323();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};

ADCCard::ADCCard(): amplifying_factor{1.0}, selected_channel{1} {
    // ... voor alle kaarten benodigde code
    println("initialisatie is gestart.");
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
    println("AD178 is geinitialiseeerd.");
}
void AD178::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de AD178 benodigde code
    println("Kanaal {} van AD178 is geselecteerd.", channel);
}
void AD178::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de AD178 benodigde code
    println("Versterkingsfactor van AD178 is {:.2f}.", factor);
}
int AD178::sample() const {
    // ... de specifieke voor de AD178 benodigde code
    return 0x7FFF; // +5 * amplifying_factor V
}

NI323::NI323() {
    // ... de specifieke voor de NI323 benodigde code
    println("NI323 is geinitialiseeerd.");
}
void NI323::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de NI323 benodigde code
    println("Kanaal {} van NI323 is geselecteerd.", channel);
}
void NI323::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de NI323 benodigde code
    println("Versterkingsfactor van NI323 is {:.2f}.", factor);
}
int NI323::sample() const {
    // ... de specifieke voor de NI323 benodigde code
    return -0x8000; // -5 * amplifying_factor V
}

void do_measurement(ADCCard& card, double factor, int channel) {
    card.set_amplifier(factor);
    card.select_channel(channel);
    println("Kanaal {} = {:.2f} V.", card.get_channel(), card.read());
}

int main() {
    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
}
