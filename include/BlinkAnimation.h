//
// Created by f.wimmer on 07.09.2021.
//

#ifndef MINIMALLEDFX_BLINKANIMATION_H
#define MINIMALLEDFX_BLINKANIMATION_H
#include "AbstractAnimation.h"
class BlinkAnimation : public AbstractAnimation
{

public:
    BlinkAnimation(LED oncolor, int stepsCount);

    void reset() override;

    void setColor(LED color);

protected:
    bool onCalculate() override;
    LED onGetValueAt(int i) const override;

private:
    LED mCurrentColor;
    LED mOnColor;
    int stepsCount;
};
#endif //MINIMALLEDFX_BLINKANIMATION_H
