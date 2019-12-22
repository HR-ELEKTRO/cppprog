#ifndef _bb674_
#define _bb674_

#include "adccard.h"

class BB647: public Adccard {
public:
    BB647();
    virtual void select_channel(int channel);
    virtual void set_amplifier(double factor);
private:
    virtual int sample() const;
};

#endif

