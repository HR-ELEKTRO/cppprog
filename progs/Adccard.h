#ifndef _adccard_
#define _adccard_

class ADCCard {
public:
    ADCCard();
    virtual ~ADCCard() = default;
    virtual void selectChannel(int channel) = 0;
    int getChannel() const;
    virtual void setAmplifier(double factor) = 0;
    double read() const;
protected:
    void rememberChannel(int channel);
    void rememberAmplifier(double factor);
private:
    double amplifyingFactor;
    int selectedChannel;
    virtual int sample() const = 0;
};

#endif

