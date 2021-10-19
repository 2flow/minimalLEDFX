//
// Created by f.wimmer on 10.08.2021.
//

#include "AbstractAnimation.h"

AbstractAnimation::AbstractAnimation(size_t maxSteps)
        : mMaxSteps{maxSteps}, mNextMaxSteps{maxSteps}
{
    animationObserver = &this->singleObserver;
}

void AbstractAnimation::reset(){
    mCurrentStep = 0;
    mReady = false;
    mMaxSteps = mNextMaxSteps;
    mState = State::Running;
}

void AbstractAnimation::nextFrame(){
    if ((mCurrentStep < mMaxSteps) && (mState == State::Running)) {
        mReady = false;
        mCurrentStep++;
    }else if(mState == State::Running){
        mMaxSteps = mNextMaxSteps;
        onFinished();
        mState = State::Finished;
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

bool AbstractAnimation::isReversed() const {
    return mIsReversed;
}

void AbstractAnimation::setReversed(bool isReversed) {
    mIsReversed = isReversed;
}

void AbstractAnimation::setLedCount(size_t count) {
    if(count != mLedCount){
        mLedCount = count;
        reset();
    }
}

LED AbstractAnimation::getValueAt(int i) const {
    if(mIsReversed){
        if(i < mLedCount) {
            i = static_cast<int>(mLedCount) - 1 - i;
        }else{
            i = 0;
        }
    }

    return onGetValueAt(i);
}

size_t AbstractAnimation::getLedCount() const {
    return mLedCount;
}

void AbstractAnimation::setMaxSteps(size_t steps) {
    mNextMaxSteps = steps;
}