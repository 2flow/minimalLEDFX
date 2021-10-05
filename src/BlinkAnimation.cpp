//
// Created by f.wimmer on 07.09.2021.
//
#include "BlinkAnimation.h"

BlinkAnimation::BlinkAnimation(LED oncolor, int _stepsCount) : AbstractAnimation{_stepsCount}, mOnColor{oncolor}
{
    stepsCount = _stepsCount;
}

void BlinkAnimation::reset()
{
    AbstractAnimation::reset();
}

bool BlinkAnimation::onCalculate()
{

    if (getCurrentStep() > (stepsCount / 2) && getCurrentStep() <= stepsCount)
    {
        mCurrentColor = {0, 0, 0};
    }
    else
    {
        mCurrentColor = mOnColor;
    }

    // currentValue = valueSteps * static_cast<float>(getCurrentStep());

    // if(currentValue > 1.0){
    //     currentValue = 1.0;
    // }

    // float oldMultiplier = 1.0F - currentValue;

    // current.red = from.red * oldMultiplier + to.red * currentValue;
    // current.green = from.green * oldMultiplier + to.green * currentValue;
    // current.blue = from.blue * oldMultiplier + to.blue * currentValue;

    return true;
}

LED BlinkAnimation::getValueAt(int i) const
{
    return mCurrentColor;
}


