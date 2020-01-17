#ifndef _ni323_
#define _ni323_
#include "Adccard.h"

class NI323: public ADCCard {
public:
    NI323();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};

#endif
