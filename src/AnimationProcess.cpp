//
// Created by f.wimmer on 09.08.2021.
//


#include "AnimationProcess.h"

AnimationProcess::AnimationProcess(int fps, int startIdx, int length) : msPerFrame{1000 / fps}, fps{fps}{

    this->startIdx = startIdx;
    this->length = length;
}

void AnimationProcess::setAnimation(IAnimation *animation) {
    this->currentAnimation = animation;
}

void AnimationProcess::milliSecondTick() {
    currentMsOfFrame ++;

    if(currentMsOfFrame == msPerFrame){
        currentMsOfFrame = 0;
        needsDraw = true;
    }
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
        if(currentAnimation->isReady() && needsDraw){
            if(ledSink->getType() == IMMEDIATE){
                drawToSink();
            }

            ledSink->show();
            currentAnimation->nextFrame();
            needsDraw = false;
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
        }
    }
}

void AnimationProcess::reset() {
    if(currentAnimation != nullptr){
        currentAnimation->reset();
    }
    currentMsOfFrame = 0;
    needsDraw = true;
}

void AnimationProcess::setLedSink(ILedSink *sink) {
    this->ledSink = sink;
}

void AnimationProcess::addObserver(IAnimationObserver *observer) {
    if(animationObserver != nullptr){
        animationObserver->addObserver(observer);
    }
}

void AnimationProcess::removeObserver(IAnimationObserver *observer) {
    if(animationObserver != nullptr){
        animationObserver->removeObserver(observer);
    }
}
