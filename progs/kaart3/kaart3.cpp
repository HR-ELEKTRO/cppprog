// Een object georienteerde oplossing verdeeld over verschillende files

import AD178;
import NI323;
import do_measurement;

int main() {
    AD178 card1;
    do_measurement(card1, 10, 3);
    NI323 card2;
    do_measurement(card2, 5, 4);
}
