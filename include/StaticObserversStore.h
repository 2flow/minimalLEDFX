//
// Created by f.wimmer on 06.09.2021.
//

#ifndef MINIMALLEDFX_REPEATOBSERVER_H
#define MINIMALLEDFX_REPEATOBSERVER_H
#include "IAnimationObserver.h"

template <int OBSERVERS_COUNT>
class StaticObserversStore : public AbstractAnimationObservers{
public:
    void addObserver(IAnimationObserver *observer) override;
    void removeObserver(IAnimationObserver *observer) override;

    void animationEnd(IAnimation *animation) override;
    void animationStart(IAnimation *animation) override;

private:
    int observerCount = 0;
    IAnimationObserver *observers[OBSERVERS_COUNT];
};


template <int OBSERVERS_COUNT>
void StaticObserversStore<OBSERVERS_COUNT>::addObserver(IAnimationObserver *observer) {
    if(observerCount < OBSERVERS_COUNT){
        observers[observerCount] = observer;
        observerCount ++;
    }
}

template <int OBSERVERS_COUNT>
void StaticObserversStore<OBSERVERS_COUNT>::removeObserver(IAnimationObserver *observer) {
    bool found = false;
    for (int i = 0; i < observerCount; ++i) {
        if(observers[i] == observer){
            found = true;
        }

        if (found){
            observers[i] = (i < (observerCount - 1))
                    ? observers[i + 1]
                    : nullptr;
        }
    }
    if(observerCount < OBSERVERS_COUNT){
        observers[observerCount] = observer;
        observerCount ++;
    }
}

template <int OBSERVERS_COUNT>
void StaticObserversStore<OBSERVERS_COUNT>::animationEnd(IAnimation *animation){
    for (int i = 0; i < observerCount; ++i) {
        observers[i]->animationEnd(animation);
    }
}

template <int OBSERVERS_COUNT>
void StaticObserversStore<OBSERVERS_COUNT>::animationStart(IAnimation *animation){
    for (int i = 0; i < observerCount; ++i) {
        observers[i]->animationStart(animation);
    }
}
#endif //MINIMALLEDFX_REPEATOBSERVER_H
