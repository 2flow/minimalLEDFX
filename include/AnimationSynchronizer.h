//
// Created by f.wimmer on 05.10.2021.
//

#ifndef MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H
#define MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H


class AbstractAnimation;

class AnimationSynchronizer {
public:

    int getCurrentStep(AbstractAnimation* self);
    int getMaxSteps(AbstractAnimation* self);

    bool getReady(AbstractAnimation* self);


    /**
     * Will return true if the master animation inside is the caller
     * @param self
     * @return
     */
    bool reset(AbstractAnimation* self);
    bool isReset() const;

    /**
     * Will reset the reset flag, needs to be called at least once every loop
     * @param self
     */
    void quitReset(AbstractAnimation* self);

private:
    AbstractAnimation* mMasterAnimation = nullptr;
    bool mReset = false;
    void checkMaster(AbstractAnimation* self);
};


#endif //MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H
