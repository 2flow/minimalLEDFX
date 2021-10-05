//
// Created by f.wimmer on 09.08.2021.
//

#ifndef UNTITLED_IANIMATIONPROCESS_H
#define UNTITLED_IANIMATIONPROCESS_H
class IAnimationProcess{
public:
    virtual void process() = 0;
    virtual void reset() = 0;
    virtual void pause() = 0;
    virtual void play() = 0;
};
#endif //UNTITLED_IANIMATIONPROCESS_H
