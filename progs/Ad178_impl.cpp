module hr.brojz.adc.ad178;
import std;
using namespace std;

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
    return 0x7FFF; // +5 * f V
}
