module hr.brojz.adc.bb647;
import std;
using namespace std;

BB647::BB647() {
    // ... de specifieke voor de BB647 benodigde code
    println("BB647 is geinitialiseeerd.");
}
void BB647::select_channel(int channel) {
    remember_channel(channel);
    // ... de specifieke voor de BB647 benodigde code
    println("Kanaal {} van BB647 is geselecteerd.", channel);
}
void BB647::set_amplifier(double factor) {
    remember_amplifier(factor);
    // ... de specifieke voor de BB647 benodigde code
    println("Versterkingsfactor van BB647 is {:.2f}.", factor);
}
int BB647::sample() const {
    // ... de specifieke voor de BB647 benodigde code
    return 0x4000; // 2.5 * f V
}
