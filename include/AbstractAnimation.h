//
// Created by f.wimmer on 10.08.2021.
//

#ifndef UNTITLED_ABSTRACTANIMATION_H
#define UNTITLED_ABSTRACTANIMATION_H


#include "IAnimation.h"
#include "IAnimationObserver.h"
#include "StaticObserversStore.h"

class AbstractAnimation : public IAnimation{
public:
    AbstractAnimation(int maxSteps);

    void reset() override;
    void nextFrame() override;
    bool calculate() override;

    bool isReady() const override;

    void addObserver(IAnimationObserver *observer);
    void removeObserver(IAnimationObserver *observer);

protected:
    int getCurrentStep() const;
    int getMaxSteps() const;

    virtual bool onCalculate() = 0;
    virtual void onFinished();

    StaticObserversStore<1> singleObserver;
    AbstractAnimationObservers *animationObserver = nullptr;

private:
    int currentStep = 0;
    int maxSteps = 0;
    bool ready = false;

};

#endif //UNTITLED_ABSTRACTANIMATION_H
