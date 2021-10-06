//
// Created by f.wimmer on 05.10.2021.
//

#include "AbstractAnimation.h"
#include "AnimationSynchronizer.h"

int AnimationSynchronizer::getCurrentStep(AbstractAnimation *self) {
    checkMaster(self);
    return mMasterAnimation->getCurrentStep();
}

void AnimationSynchronizer::checkMaster(AbstractAnimation *self) {
    if(mMasterAnimation == nullptr){
        mMasterAnimation = self;
    }
}

int AnimationSynchronizer::getMaxSteps(AbstractAnimation *self) {
    checkMaster(self);

    return mMasterAnimation->getMaxSteps();
}

bool AnimationSynchronizer::getReady(AbstractAnimation *self) {
    checkMaster(self);
    return mMasterAnimation->getReady();
}

bool AnimationSynchronizer::reset(AbstractAnimation *self) {
    checkMaster(self);
    if(mMasterAnimation == self){
        mReset = true;
        return true;
    }

    return false;
}

bool AnimationSynchronizer::isReset() const {
    return mReset;
}

void AnimationSynchronizer::quitReset(AbstractAnimation *self) {
    checkMaster(self);
    if(mMasterAnimation == self){
        mReset = false;
    }
}
