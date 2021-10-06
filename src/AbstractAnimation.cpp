//
// Created by f.wimmer on 10.08.2021.
//

#include "AbstractAnimation.h"

AbstractAnimation::AbstractAnimation(int maxSteps)
        : mMaxSteps{maxSteps}
{
    animationObserver = &this->singleObserver;
}

void AbstractAnimation::reset(){
    mCurrentStep = 0;
    mReady = false;
}

void AbstractAnimation::nextFrame(){
    if (mCurrentStep < mMaxSteps) {
        mReady = false;
        mCurrentStep++;
    }else{
        onFinished();
    }
}

bool AbstractAnimation::calculate(){
    if(mSynchronizer != nullptr){
        if((mCurrentStep != mSynchronizer->getCurrentStep(this)) ||
            (mMaxSteps != mSynchronizer->getMaxSteps(this))) {
            mCurrentStep = mSynchronizer->getCurrentStep(this);
            mMaxSteps = mSynchronizer->getMaxSteps(this);
            mReady = false;
        }
    }

    if (!mReady){
        mReady = onCalculate();
    }

    return mReady;
}

bool AbstractAnimation::isReady() const{
    return mReady;
}

int AbstractAnimation::getCurrentStep() const{
    return mCurrentStep;
}

int AbstractAnimation::getMaxSteps() const{
    return mMaxSteps;
}

void AbstractAnimation::addObserver(IAnimationObserver *observer) {
    if(animationObserver != nullptr){
        animationObserver->addObserver(observer);
    }
}

void AbstractAnimation::removeObserver(IAnimationObserver *observer) {
    if(animationObserver != nullptr){
        animationObserver->removeObserver(observer);
    }
}

void AbstractAnimation::onFinished() {
    if(animationObserver != nullptr){
        animationObserver->animationEnd(this);
    }
}

bool AbstractAnimation::getReady() const {
    return mReady;
}

void AbstractAnimation::synchronizeWith(AnimationSynchronizer *synchronizer) {
    mSynchronizer = synchronizer;
}

void AbstractAnimation::cancelSynchronization() const {
    if(mSynchronizer != nullptr){
        mSynchronizer->removeAsSource(this);
    }
}
