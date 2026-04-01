export module hr.brojz.adc.ad178;

import hr.brojz.adc;

export class AD178: public ADCCard {
public:
    AD178();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};
