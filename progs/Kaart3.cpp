// Een object georienteerde oplossing verdeeld over verschillende files

import hr.brojz.adc.ad178;
import hr.brojz.adc.ni323;
import hr.brojz.adc.do_measurement;

int main() {
    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
}
