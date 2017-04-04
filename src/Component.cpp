//
// Created by Neuron on 03/04/2017.
//

#include "Component.h"

void Component::prepare(unsigned long milli) {
    _prepareTimers.tick(milli);
}

void Component::tick(unsigned long milli) {
    _tickTimers.tick(milli);
}

void Component::addPrepareTimer(const Timer &timer) {
    _prepareTimers.add(timer);
}

void Component::removePrepareTimer(const Timer &timer) {
    _prepareTimers.remove(timer);
}

void Component::addTickTimer(const Timer &timer) {
    _tickTimers.add(timer);
}

void Component::removeTickTimer(const Timer &timer) {
    _tickTimers.remove(timer);
}