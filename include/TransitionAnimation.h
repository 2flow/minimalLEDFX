//
// Created by f.wimmer on 10.08.2021.
//

#ifndef UNTITLED_TRANSITIONANIMATION_H
#define UNTITLED_TRANSITIONANIMATION_H

#include "AbstractAnimation.h"

class TransitionAnimation : public AbstractAnimation {
public:

    void reset(bool resetToAnimation);

protected:
    bool onCalculate() override;
    LED onGetValueAt(int i) const override;

    void reset() override;

private:
    IAnimation* fromAnimation;
    IAnimation* toAnimation;

};


#endif //UNTITLED_TRANSITIONANIMATION_H
