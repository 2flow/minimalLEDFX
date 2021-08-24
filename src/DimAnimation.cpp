//
// Created by f.wimmer on 09.08.2021.
//

#include "DimAnimation.h"



DimAnimation::DimAnimation(LED from, LED to, int stepsCount) :
    AbstractAnimation{stepsCount}, from{from}, to{to}, current(0,0,0){

    onConfigure(stepsCount);
}

void DimAnimation::reset(){
    currentValue = 0.0;
    AbstractAnimation::reset();
}


void DimAnimation::onConfigure(int stepsCount){
    valueSteps = 1.0F / static_cast<float>(stepsCount);
}

bool DimAnimation::onCalculate(){
    currentValue = valueSteps * static_cast<float>(getCurrentStep());

    if(currentValue > 1.0){
        currentValue = 1.0;
    }

    float oldMultiplier = 1.0F - currentValue;

    current.red = from.red * oldMultiplier + to.red * currentValue;
    current.green = from.green * oldMultiplier + to.green * currentValue;
    current.blue = from.blue * oldMultiplier + to.blue * currentValue;

    return true;
}

LED DimAnimation::getValueAt(int i) const{
    return current;
}

void DimAnimation::setFromColor(LED from) {
    this->from = from;
}

void DimAnimation::setToColor(LED color) {
    this->to = color;
}
