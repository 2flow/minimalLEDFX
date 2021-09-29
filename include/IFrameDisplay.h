//
// Created by f.wimmer on 29.09.2021.
//

#ifndef MINIMALLEDFX_IFRAMEDISPLAY_H
#define MINIMALLEDFX_IFRAMEDISPLAY_H


class IFrameDisplay {
public:
    virtual void display() = 0;

    virtual ~IFrameDisplay() = default;
};


#endif //MINIMALLEDFX_IFRAMEDISPLAY_H
