//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_IANIMATION_H
#define UNTITLED_IANIMATION_H
#include <stdint.h>
#include "LED.h"

class IAnimation{
public:
    /**
     * Prepare the next output set
     * @return
     */
    virtual bool calculate() = 0;
    virtual void nextFrame() = 0;
    virtual void reset() = 0;
    virtual bool isReady() const = 0;

    virtual LED getValueAt(int i) const = 0;
};
#endif //UNTITLED_IANIMATION_H
