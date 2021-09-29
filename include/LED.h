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

    LED operator*(float value) const{
        return LED{red * value, green * value, blue * value};
    }

    LED operator*(double _value) const{
        auto value = static_cast<float>(_value);
        return LED{red * value, green * value, blue * value};
    }


};

#endif //UNTITLED_LED_H
