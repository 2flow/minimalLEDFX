//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_LED_H
#define UNTITLED_LED_H
#include "stdint.h"
class LED{
public:
    LED(float red = 0, float green = 0, float blue = 0)
        : red{red}, blue{blue}, green{green}{}

    float red = 0;
    float blue = 0;
    float green = 0;
};

#endif //UNTITLED_LED_H
