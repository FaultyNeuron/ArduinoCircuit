//
// Created by Neuron on 04/04/2017.
//

#include "Animation.h"

void Animation::tick(unsigned long millis) {
    _timers.tick(millis);
}

bool Animation::isActive() {
    return _isActive;
}

void Animation::setActive(bool active) {
    _isActive = active;
}

struct T : public PeriodicTimer {
private:
    Animation& _animation;
    T(unsigned long timerDelay, unsigned long currentTime, Animation &_animation) :
            PeriodicTimer(timerDelay, currentTime), _animation(_animation) {}

    virtual bool action(unsigned long millis) override {
        return PeriodicTimer::action(millis);
    }
};

Animation::Animation(unsigned long animationDelay, unsigned long milli) : _timer(animationDelay, milli){
    _timers.add(_timer);
}
