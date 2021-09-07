#include "RepeatObserver.h"

void RepeatObserver::animationEnd(IAnimation *animation) {
    animation->reset();
}

void RepeatObserver::animationStart(IAnimation *animation) {

}
