//
// Created by f.wimmer on 10.08.2021.
//

#include "TransitionAnimation.h"

bool TransitionAnimation::onCalculate() {
    return false;
}

LED TransitionAnimation::onGetValueAt(int i) const {
    return LED();
}

void TransitionAnimation::reset(bool resetToAnimation) {

    if(resetToAnimation && (toAnimation != nullptr)){

    }

    reset();
}

void TransitionAnimation::reset() {
    AbstractAnimation::reset();
}

