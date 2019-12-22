#ifndef _adccard_
#define _adccard_

class ADCCard {
public:
    ADCCard();
    virtual ~ADCCard() = default;
    virtual void select_channel(int channel) = 0;
    int get_channel() const;
    virtual void set_amplifier(double factor) = 0;
    double read() const;
protected:
    void remember_channel(int channel);
    void remember_amplifier(double factor);
private:
    double amplifying_factor;
    int selected_channel;
    virtual int sample() const = 0;
};

#endif

