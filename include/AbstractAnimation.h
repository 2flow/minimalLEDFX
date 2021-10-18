//
// Created by f.wimmer on 10.08.2021.
//

#ifndef UNTITLED_ABSTRACTANIMATION_H
#define UNTITLED_ABSTRACTANIMATION_H

#include <cstddef>
#include "IAnimation.h"
#include "IAnimationObserver.h"
#include "StaticObserversStore.h"
#include "AnimationSynchronizer.h"
#include "LED.h"

class AbstractAnimation : public IAnimation{
public:
    AbstractAnimation(size_t maxSteps);

    void reset() override;
    void nextFrame() override;
    bool calculate() override;

    bool isReady() const override;

    void addObserver(IAnimationObserver *observer);
    void removeObserver(IAnimationObserver *observer);

    int getCurrentStep() const;
    int getMaxSteps() const;
    bool getReady() const;

    bool isReversed() const;
    void setReversed(bool isReversed);

    void setLedCount(size_t count) override;
    size_t getLedCount() const;

    void synchronizeWith(AnimationSynchronizer* synchronizer);
    void cancelSynchronization() const;

    void setMaxSteps(size_t steps);

    LED getValueAt(int i) const override;
protected:

    virtual bool onCalculate() = 0;
    virtual void onFinished();

    virtual LED onGetValueAt(int i) const = 0;

    StaticObserversStore<1> singleObserver;
    AbstractAnimationObservers *animationObserver = nullptr;

private:
    size_t mCurrentStep = 0;
    size_t mMaxSteps = 0;
    bool mReady = false;
    bool mIsReversed = false;

    size_t mLedCount = 0;

    AnimationSynchronizer* mSynchronizer = nullptr;

};

#endif //UNTITLED_ABSTRACTANIMATION_H
