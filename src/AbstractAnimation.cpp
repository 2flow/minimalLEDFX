//
// Created by f.wimmer on 10.08.2021.
//

#include "AbstractAnimation.h"

AbstractAnimation::AbstractAnimation(int maxSteps)
        : maxSteps{maxSteps}
{
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
        //Serial.println("Done with animation");
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

