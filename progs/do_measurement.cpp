module hr.brojz.adc.do_measurement;
import std;
using namespace std;

void do_measurement(ADCCard& card, double factor, int channel) {
    card.set_amplifier(factor);
    card.select_channel(channel);
    println("Kanaal {} = {:.2f} V.", card.get_channel(), card.read());
}
