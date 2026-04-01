module hr.brojz.adc;
import std;
using namespace std;

ADCCard::ADCCard(): amplifying_factor(1.0), selected_channel(1) {
    // voor alle kaarten benodigde code
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
