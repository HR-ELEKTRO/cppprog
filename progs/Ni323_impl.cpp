module hr.brojz.adc.ni323;
import std;
using namespace std;

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
    return -0x8000; // -5 * f V
}

