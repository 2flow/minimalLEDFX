//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_ILEDSINK_H
#define UNTITLED_ILEDSINK_H
#include <stdint.h>
#include "LED.h"

enum TDisplayType{
    IMMEDIATE,
    BUFFERED
};

class ILedSink{
public:
    virtual void setValueAt(int i, LED value) = 0;
    virtual TDisplayType getType() const = 0;
    virtual void show() = 0;
};

#endif //UNTITLED_ILEDSINK_H
