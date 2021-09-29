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
            default: {
                if (mRequestCalculate) {
                    mState = TState::Calculate;
                }
                break;
            }
        }

        /*if(currentAnimation->isReady()){
            if(ledSink->getType() == IMMEDIATE){
                drawToSink();
            }
        }else if(!currentAnimation->isReady()){

            if (needsDraw){
                // TODO log something because the timing is not correct
            }

            currentAnimation->calculate();

            // TODO move to state machine, (needs to be created first)
            // draw to buffered sink if ready after the calculation
            if (currentAnimation->isReady() && (ledSink->getType() == BUFFERED)){
                drawToSink();
            }
        }*/
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
    if(currentAnimation != nullptr){
        currentAnimation->nextFrame();
    }

    mRequestCalculate = true;
}


