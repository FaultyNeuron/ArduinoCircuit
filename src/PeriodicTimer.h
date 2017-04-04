//
// Created by Neuron on 03/04/2017.
//

#ifndef BASIC_PERIODIC_TIMER_H
#define BASIC_PERIODIC_TIMER_H

#include "Timer.h"

class PeriodicTimer : public Timer {
public:
    PeriodicTimer(unsigned long timerDelay, unsigned long currentTime);
    unsigned long nextTickAt() const;
    virtual bool action(unsigned long millis) override;

private:
    unsigned long _timerDelay;
    unsigned long _nextTickAt = 0;
};


#endif //BASIC_TIMER_H
