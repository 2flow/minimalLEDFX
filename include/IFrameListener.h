//
// Created by f.wimmer on 29.09.2021.
//

#ifndef MINIMALLEDFX_IFRAMELISTENER_H
#define MINIMALLEDFX_IFRAMELISTENER_H


class IFrameListener {
public:

    virtual void drawFrame() = 0;
    virtual void nextFrame() = 0;

    virtual ~IFrameListener() = default;
};


#endif //MINIMALLEDFX_IFRAMELISTENER_H
