//
// Created by Neuron on 03/04/2017.
//

#ifndef BASICS_COMPONENT_H
#define BASICS_COMPONENT_H

#include <vector>
#include "PeriodicTimer.h"
#include "TimerManager.h"

using namespace std;

class Component {
public:
    virtual void tick(unsigned long millis);
    virtual void prepare(unsigned long millis);

    void addPrepareTimer(Timer &listener);

    void removePrepareTimer(Timer &listener);

    void addTickTimer(Timer &listener);

    void removeTickTimer(Timer &listener);

private:
    TimerManager _prepareTimers;
    TimerManager _tickTimers;
};


#endif //BASICS_COMPONENT_H
