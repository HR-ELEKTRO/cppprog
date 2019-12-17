#ifndef _ni323_
#define _ni323_
#include "adccard.h"

class NI323: public ADCCard {
public:
    NI323();
    virtual void selectChannel(int channel);
    virtual void setAmplifier(double factor);
private:
    virtual int sample() const;
};

#endif
