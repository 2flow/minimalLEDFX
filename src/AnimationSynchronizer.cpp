//
// Created by f.wimmer on 05.10.2021.
//

#include "AbstractAnimation.h"
#include "AnimationSynchronizer.h"

int AnimationSynchronizer::getCurrentStep(AbstractAnimation *pSelf) {
    checkMaster(pSelf);
    return mMasterAnimation->getCurrentStep();
}

void AnimationSynchronizer::checkMaster(AbstractAnimation *pSelf) {
    if(mMasterAnimation == nullptr){
        mMasterAnimation = pSelf;
    }
}

int AnimationSynchronizer::getMaxSteps(AbstractAnimation *pSelf) {
    checkMaster(pSelf);

    return mMasterAnimation->getMaxSteps();
}

bool AnimationSynchronizer::getReady(AbstractAnimation *pSelf) {
    checkMaster(pSelf);
    return mMasterAnimation->getReady();
}

bool AnimationSynchronizer::reset(AbstractAnimation *pSelf) {
    checkMaster(pSelf);
    if(mMasterAnimation == pSelf){
        mReset = true;
        return true;
    }

    return false;
}

bool AnimationSynchronizer::isReset() const {
    return mReset;
}

void AnimationSynchronizer::quitReset(AbstractAnimation *pSelf) {
    checkMaster(pSelf);
    if(mMasterAnimation == pSelf){
        mReset = false;
    }
}

void AnimationSynchronizer::removeAsSource(const AbstractAnimation *pSelf) {
    if(mMasterAnimation == pSelf){
        mMasterAnimation = nullptr;
    }
}
