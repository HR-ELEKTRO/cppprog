// Een object georienteerde oplossing ... wel HERBRUIKBAAR wel AANPASBAAR wel UITBREIDBAAR

#include <iostream>

using namespace std;

class ADCCard {
public:
    ADCCard();
    virtual ~ADCCard() = default;
    virtual void selectChannel(int channel) = 0;
    int getChannel() const;
    virtual void setAmplifier(double factor) = 0;
    double read() const;
protected:
    void rememberChannel(int channel);
    void rememberAmplifier(double factor);
private:
    double amplifyingFactor;
    int selectedChannel;
    virtual int sample() const = 0;
};

class AD178: public ADCCard {
public:
    AD178();
    virtual void selectChannel(int channel);
    virtual void setAmplifier(double factor);
private:
    virtual int sample() const;
};

class NI323: public ADCCard {
public:
    NI323();
    virtual void selectChannel(int channel);
    virtual void setAmplifier(double factor);
private:
    virtual int sample() const;
};

ADCCard::ADCCard(): amplifyingFactor(1.0), selectedChannel(1) {
    // ... voor alle kaarten benodigde code
    cout << "initialisatie is gestart." << endl;
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
    return 0x7FFF; // +5 * amplifyingFactor V
}

NI323::NI323() {
    // ... de specifieke voor de NI323 benodigde code
    cout << "NI323 is geinitialiseeerd." << endl;
}
void NI323::selectChannel(int channel) {
    rememberChannel(channel);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Kanaal " << channel << " van NI323 is geselecteerd." << endl;
}
void NI323::setAmplifier(double factor) {
    rememberAmplifier(factor);
    // ... de specifieke voor de NI323 benodigde code
    cout << "Versterkingsfactor van NI323 is " << factor << "." << endl;
}
int NI323::sample() const {
    // ... de specifieke voor de NI323 benodigde code
    return -0x8000; // -5 * amplifyingFactor V
}

void doIt(ADCCard& selectedChannel) {
    selectedChannel.setAmplifier(10);
    selectedChannel.selectChannel(3);
    cout << "Kanaal " << selectedChannel.getChannel() << " = " << selectedChannel.read() << " V." << endl;
}

int main() {
    // druk alle doubles af met 2 cijfers na de decimale punt
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout.precision(2);
    
    AD178 card1;
    doIt(card1);
    NI323 card2;
    doIt(card2);

    cin.get();
    return 0;
}
