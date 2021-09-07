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

class AnimationProcess : public IAnimationProcess{
public:
    AnimationProcess(int fps, int startIdx, int length);
    void milliSecondTick() override;
    void process() override;
    void reset() override;

    void setAnimation(IAnimation * animation);
    void setLedSink(ILedSink *sink);


private:
    const int msPerFrame;
    const int fps;
    int currentMsOfFrame = 0;

    bool needsDraw = true;
    IAnimation *currentAnimation = nullptr;
    ILedSink *ledSink = nullptr;

    int startIdx;
    int length;

    void drawToSink() const;
};


#endif //UNTITLED_ANIMATIONPROCESS_H
