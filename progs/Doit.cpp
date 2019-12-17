#include <iostream>
#include <iomanip>
using namespace std;

#include "adccard.h"

void doIt(ADCCard& c) {
    c.setAmplifier(10);
    c.selectChannel(3);
    cout << "Kanaal " << c.getChannel() << " = " << c.read() << " V." << endl;
}

