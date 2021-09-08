//
// Created by f.wimmer on 10.08.2021.
//

#include "AbstractAnimation.h"

AbstractAnimation::AbstractAnimation(int maxSteps)
        : maxSteps{maxSteps}
{
    animationObserver = &this->singleObserver;
}

void AbstractAnimation::reset(){
    currentStep = 0;
    ready = false;
}

void AbstractAnimation::nextFrame(){
    if (currentStep < maxSteps) {
        ready = false;
        currentStep++;
    }else{
        if(animationObserver != nullptr){
            animationObserver->animationEnd(this);
        }
    }
}

bool AbstractAnimation::calculate(){
    if (!ready){
        ready = onCalculate();
    }

    return ready;
}

bool AbstractAnimation::isReady() const{
    return ready;
}

int AbstractAnimation::getCurrentStep() const{
    return currentStep;
}

int AbstractAnimation::getMaxSteps() const{
    return maxSteps;
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