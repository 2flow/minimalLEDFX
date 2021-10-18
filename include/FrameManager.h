//
// Created by f.wimmer on 29.09.2021.
//

#ifndef MINIMALLEDFX_FRAMEMANAGER_H
#define MINIMALLEDFX_FRAMEMANAGER_H

#include "IDisplayTarget.h"
#include "IFrameListener.h"

#include <stdint.h>

class IFrameManager {
public:
    virtual void millisecondTick() = 0;

    virtual void setLedSink(IDisplayTarget* sink) = 0;
    virtual void addListener(IFrameListener* listener) = 0;

    virtual void loop() = 0;
    virtual ~IFrameManager() = default;
};

template <int MAX_FRAMELISTENER>
class FrameManager : public IFrameManager {
public:
    FrameManager(int fps); // msPerFrame{1000 / fps},
    void millisecondTick() override;

    void setLedSink(IDisplayTarget* sink) override;
    void addListener(IFrameListener* listener) override;

    void loop() override;
private:

    const int mMsPerFrame{0};
    const int mFPS{0};
    int mCurrentMsOfFrame = 1;
    bool mIsNextFrame = false;

    IDisplayTarget* mLedSink = nullptr;

    unsigned int mListenerCount = 0;
    IFrameListener* mListeners[MAX_FRAMELISTENER]{};
};

template<int MAX_FRAMELISTENER>
FrameManager<MAX_FRAMELISTENER>::FrameManager(int fps) : mMsPerFrame{1000 / fps}, mFPS{fps}{

}

template<int MAX_FRAMELISTENER>
void FrameManager<MAX_FRAMELISTENER>::millisecondTick() {
    mCurrentMsOfFrame ++;
    if(mCurrentMsOfFrame >= mMsPerFrame){
        mCurrentMsOfFrame = 0;
        mIsNextFrame = true;
    }
}

template<int MAX_FRAMELISTENER>
void FrameManager<MAX_FRAMELISTENER>::loop() {
    if(mIsNextFrame){
        for(unsigned int i = 0; i < mListenerCount; i ++){
            auto listener = mListeners[i];
            listener->drawFrame();
            listener->nextFrame();
        }
        if(mLedSink != nullptr) {
            mLedSink->show();
        }

        mIsNextFrame = false;
    }
}

template<int MAX_FRAMELISTENER>
void FrameManager<MAX_FRAMELISTENER>::setLedSink(IDisplayTarget *sink) {
    mLedSink = sink;
}

template<int MAX_FRAMELISTENER>
void FrameManager<MAX_FRAMELISTENER>::addListener(IFrameListener *listener) {
    if(mListenerCount < MAX_FRAMELISTENER){
        mListeners[mListenerCount] = listener;
        mListenerCount++;
    }
}
/*
 *
 milliSecondTick() {
    currentMsOfFrame ++;

    if(currentMsOfFrame == msPerFrame){
        currentMsOfFrame = 0;
        needsDraw = true;
    }
}
 */

#endif //MINIMALLEDFX_FRAMEMANAGER_H
