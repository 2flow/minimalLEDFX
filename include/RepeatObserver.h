//
// Created by f.wimmer on 07.09.2021.
//

#ifndef MINIMALLEDFX_REPEATOBSERVER_H
#define MINIMALLEDFX_REPEATOBSERVER_H
#include "IAnimationObserver.h"

class RepeatObserver : public IAnimationObserver{
public:
    void animationEnd(IAnimation *animation) override;
    void animationStart(IAnimation *animation) override;
};
#endif //MINIMALLEDFX_REPEATOBSERVER_H
