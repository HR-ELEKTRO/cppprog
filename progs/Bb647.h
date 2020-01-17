#ifndef _bb674_
#define _bb674_

#include "Adccard.h"

class BB647: public ADCCard {
public:
    BB647();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};

#endif
