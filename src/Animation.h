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
    struct T : public PeriodicTimer {
    public:
        T(unsigned long timerDelay, unsigned long currentTime, Animation &_animation) :
                PeriodicTimer(timerDelay, currentTime), _animation(_animation) {}
        virtual bool action(unsigned long millis) override {
            _animation.nextFrame();
            return PeriodicTimer::action(millis);
        }
    private:
        Animation& _animation;
    };

    bool _isActive;
    T _timer;
    TimerManager _timers;
};


#endif //BASIC_ANIMATION_H
