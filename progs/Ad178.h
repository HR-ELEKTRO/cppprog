#ifndef _ad178_
#define _ad178_
#include "adccard.h"

class AD178: public ADCCard {
public:
    AD178();
    virtual void selectChannel(int channel);
    virtual void setAmplifier(double factor);
private:
    virtual int sample() const;
};

#endif
