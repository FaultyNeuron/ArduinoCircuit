//
// Created by Neuron on 04/04/2017.
//

#ifndef BASIC_ANIMATION_H
#define BASIC_ANIMATION_H


#include "PeriodicTimer.h"
#include "TimerManager.h"

class Animation {
public:
    Animation(unsigned long animationDelay, unsigned long milli);
    virtual void tick(unsigned long millis);
    bool isActive();
    void setActive(bool active);
    virtual void nextFrame() = 0;
private:
    bool _isActive;
    PeriodicTimer _timer;
    TimerManager _timers;
};


#endif //BASIC_ANIMATION_H
