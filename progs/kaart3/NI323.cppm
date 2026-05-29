export module NI323;

import ADCCard;

export class NI323: public ADCCard {
public:
    NI323();
    void select_channel(int channel) override;
    void set_amplifier(double factor) override;
private:
    int sample() const override;
};
