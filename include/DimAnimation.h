//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_DIMANIMATION_H
#define UNTITLED_DIMANIMATION_H

#include "AbstractAnimation.h"

class DimAnimation : public AbstractAnimation{

public:
    DimAnimation(LED from, LED to, int stepsCount);
    void reset() override;

    LED getValueAt(int i) const override;
    void setFromColor(LED from);
    void setToColor(LED color);

    LED getToColor() const;
protected:
    void onConfigure(int stepsCount);
    bool onCalculate() override;

private:
    float valueSteps = 0.0;
    float currentValue = 0.0;
    LED from;
    LED to;
    LED current;
};
#endif //UNTITLED_DIMANIMATION_H
