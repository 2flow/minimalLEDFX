//
// Created by f.wimmer on 10.08.2021.
//

#ifndef UNTITLED_TRANSITIONANIMATION_H
#define UNTITLED_TRANSITIONANIMATION_H

#include "AbstractAnimation.h"

class TransitionAnimation : public AbstractAnimation {
public:
    LED getValueAt(int i) const override;
    void reset(bool resetToAnimation);

protected:
    bool onCalculate() override;

    void reset() override;

private:
    IAnimation* fromAnimation;
    IAnimation* toAnimation;

};


#endif //UNTITLED_TRANSITIONANIMATION_H
