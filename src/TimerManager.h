//
// Created by Neuron on 03/04/2017.
//

#ifndef BASIC_TIMERMANAGER_H
#define BASIC_TIMERMANAGER_H

#include <StandardCplusplus.h>
#include <deque>
#include "Timer.h"

using namespace std;

class TimerManager {
public:
    void add(Timer& listener);
    void remove(Timer& listener);
    void tick(unsigned long milli);
    deque<Timer&> timers();
private:
    deque<Timer&> _timers;
};


#endif //BASIC_TIMERMANAGER_H
