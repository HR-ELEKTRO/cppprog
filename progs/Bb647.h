#ifndef _bb674_
#define _bb674_

#include "adccard.h"

class BB647: public ADCCard {
public:
    BB647();
    virtual void selectChannel(int channel);
    virtual void setAmplifier(double factor);
private:
    virtual int sample() const;
};

#endif

