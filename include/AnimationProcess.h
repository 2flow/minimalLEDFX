//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_ANIMATIONPROCESS_H
#define UNTITLED_ANIMATIONPROCESS_H

#include "IAnimationProcess.h"
#include "IAnimation.h"
#include "ILedSink.h"
#include "IAnimationObserver.h"
#include "StaticObserversStore.h"
#include "IFrameListener.h"

class AnimationProcess : public IAnimationProcess, IFrameListener{
public:
    AnimationProcess(int startIdx, int length);
    void process() override;
    void reset() override;

    void drawFrame() override;
    void nextFrame() override;

    void setAnimation(IAnimation * animation);
    void setLedSink(ILedSink *sink);

    IAnimation* getAnimation() const;

private:

    enum class TState{
        Calculate,
        WaitForDraw,
        Draw,
        WaitForNextFrame,
    };

    IAnimation *currentAnimation = nullptr;
    ILedSink *ledSink = nullptr;

    int startIdx;
    int length;

    TState mState = TState::Calculate;
    bool mRequestCalculate = false;

    void drawToSink() const;
};


#endif //UNTITLED_ANIMATIONPROCESS_H
