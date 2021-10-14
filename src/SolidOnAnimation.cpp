//
// Created by f.wimmer on 09.08.2021.
//

#include "SolidOnAnimation.h"

SolidOnAnimation::SolidOnAnimation(LED color) : AbstractAnimation{1}, mColor{color}
{
}

void SolidOnAnimation::reset()
{
    AbstractAnimation::reset();
}

bool SolidOnAnimation::onCalculate()
{
    return true;
}

LED SolidOnAnimation::onGetValueAt(int i) const
{
    return mColor;
}
