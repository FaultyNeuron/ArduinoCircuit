//
// Created by Neuron on 03/04/2017.
//

#include "PeriodicTimer.h"

PeriodicTimer::PeriodicTimer(unsigned long timerDelay, unsigned long millis) :
        _timerDelay(timerDelay),_nextTickAt(millis + timerDelay) {}

unsigned long PeriodicTimer::nextTickAt() const {
    return _nextTickAt;
}

bool PeriodicTimer::action(unsigned long millis) {
    _nextTickAt = millis + _timerDelay;
    return true;
}
