//
// Created by f.wimmer on 29.09.2021.
//

#ifndef MINIMALLEDFX_IDISPLAYTARGET_H
#define MINIMALLEDFX_IDISPLAYTARGET_H


class IDisplayTarget {
public:
    virtual void show();

    virtual ~IDisplayTarget() = default;
};


#endif //MINIMALLEDFX_IDISPLAYTARGET_H
