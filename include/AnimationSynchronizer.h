//
// Created by f.wimmer on 05.10.2021.
//

#ifndef MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H
#define MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H


class AbstractAnimation;

class AnimationSynchronizer {
public:

    int getCurrentStep(AbstractAnimation* pSelf);
    int getMaxSteps(AbstractAnimation* pSelf);

    bool getReady(AbstractAnimation* pSelf);


    /**
     * Will return true if the master animation inside is the caller
     * @param pSelf
     * @return
     */
    bool reset(AbstractAnimation* pSelf);
    bool isReset() const;

    /**
     * Will reset the reset flag, needs to be called at least once every loop
     * @param pSelf
     */
    void quitReset(AbstractAnimation* pSelf);

    void removeAsSource(const AbstractAnimation *pAnimation);

private:
    AbstractAnimation* mMasterAnimation = nullptr;
    bool mReset = false;
    void checkMaster(AbstractAnimation* pSelf);
};


#endif //MINIMALLEDFX_ANIMATIONSYNCHRONIZER_H
