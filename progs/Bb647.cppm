export module hr.brojz.adc.bb647;

import hr.brojz.adc;

export class BB647: public ADCCard {
public:
    BB647();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};
