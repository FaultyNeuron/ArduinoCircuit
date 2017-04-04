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

Animation::Animation(unsigned long animationDelay, unsigned long milli) : _timer(animationDelay, milli, *this){
    _timers.add(_timer);
}
