// Een nieuwe kaart toevoegen: het bewijs voor uitbreidbaarheid

import AD178;
import NI323;
import BB647; // new!
import do_measurement;

int main() {
    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
    BB647 card3;   // new!
    do_measurement(card3, 2, 7);
}
