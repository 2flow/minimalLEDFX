//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_SOLIDON_H
#define UNTITLED_SOLIDON_H

#include "AbstractAnimation.h"

class SolidOnAnimation : public AbstractAnimation
{

public:
    SolidOnAnimation(LED color);

    void reset() override;

protected:
    bool onCalculate() override;
    LED onGetValueAt(int i) const override;

private:
    LED mColor;
};
#endif //UNTITLED_SOLIDON_H
