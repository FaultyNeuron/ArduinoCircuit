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

    void addPrepareTimer(const Timer &listener);

    void removePrepareTimer(const Timer &listener);

    void addTickTimer(const Timer &listener);

    void removeTickTimer(const Timer &listener);

private:
    TimerManager _prepareTimers;
    TimerManager _tickTimers;
};


#endif //BASICS_COMPONENT_H
