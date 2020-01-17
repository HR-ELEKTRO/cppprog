
#ifndef _ad178_
#define _ad178_
#include "Adccard.h"

class AD178: public ADCCard {
public:
    AD178();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};

#endif
