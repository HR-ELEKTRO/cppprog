#ifndef _ni323_
#define _ni323_
#include "adccard.h"

class NI323: public ADCCard {
public:
    NI323();
    virtual void select_channel(int channel);
    virtual void set_amplifier(double factor);
private:
    virtual int sample() const;
};

#endif
