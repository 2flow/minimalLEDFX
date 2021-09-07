//
// Created by f.wimmer on 06.09.2021.
//

#ifndef MINIMALLEDFX_IANIMATIONOBSERVER_H
#define MINIMALLEDFX_IANIMATIONOBSERVER_H

#include "IAnimation.h"

class IAnimationObserver{
public:
    virtual void animationEnd(IAnimation *animation) = 0;
    virtual void animationStart(IAnimation *animation) = 0;

    virtual ~IAnimationObserver() = default;
};

class AbstractAnimationObservers : public IAnimationObserver{
public:
    virtual void addObserver(IAnimationObserver *observer) = 0;
    virtual void removeObserver(IAnimationObserver *observer) = 0;

};


#endif //MINIMALLEDFX_IANIMATIONOBSERVER_H
