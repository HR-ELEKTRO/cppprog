#ifndef _ad178_
#define _ad178_
#include "Adccard.h"

class AD178: public ADCCard {
public:
    AD178();
    virtual void select_channel(int channel);
    virtual void set_amplifier(double factor);
private:
    virtual int sample() const;
};

#endif
