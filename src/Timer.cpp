//
// Created by Neuron on 03/04/2017.
//

#include "Timer.h"

bool Timer::operator<(const Timer &other) const {
    return nextTickAt() < other.nextTickAt();
}
