//
// Created by f.wimmer on 09.08.2021.
//


#include "AnimationProcess.h"

AnimationProcess::AnimationProcess(int startIdx, int length) {
    this->startIdx = startIdx;
    this->length = length;
}

void AnimationProcess::setAnimation(IAnimation *animation) {
    this->currentAnimation = animation;
    animation->setLedCount(this->length);
}


void AnimationProcess::drawToSink() const {
    for (int i = 0; i < length; ++i) {
        ledSink->setValueAt(i + startIdx, currentAnimation->getValueAt(i));
    }
}

// state machine steps:
// calculate
// draw to buffer
// show
void AnimationProcess::process() {
    if ((currentAnimation != nullptr) && (ledSink != nullptr)){

        switch(mState)
        {
            case TState::Calculate: {
                mRequestCalculate = false;

                currentAnimation->calculate();

                if (currentAnimation->isReady() && (ledSink->getType() == BUFFERED)) {
                    mState = TState::Draw;
                } else if (currentAnimation->isReady()) {
                    mState = TState::WaitForDraw;
                }
                break;
            }
            case TState::Draw: {
                drawToSink();
                mState = TState::WaitForNextFrame;
                break;
            }
            case TState::Paused:{
                // paused do nothing
                break;
            }
            default: {
                if (mRequestCalculate) {
                    mState = TState::Calculate;
                }
                break;
            }
        }
    }
}

void AnimationProcess::reset() {
    if(currentAnimation != nullptr){
        currentAnimation->reset();
    }

    mState=TState::Calculate;
    mRequestCalculate = false;
}

void AnimationProcess::setLedSink(ILedSink *sink) {
    this->ledSink = sink;
}

IAnimation *AnimationProcess::getAnimation() const {
    return currentAnimation;
}

void AnimationProcess::drawFrame() {
    if(mState == TState::WaitForDraw){
        mState = TState::Draw;
    }
}

void AnimationProcess::nextFrame() {
    if((currentAnimation != nullptr) &&
        (mState != TState::Paused)){
        currentAnimation->nextFrame();
    }

    mRequestCalculate = true;
}

void AnimationProcess::pause() {
    mState = TState::Paused;
}

void AnimationProcess::play() {
    mState = TState::Calculate;
}


