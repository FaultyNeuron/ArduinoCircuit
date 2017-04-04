//
// Created by Neuron on 03/04/2017.
//

#include "TimerManager.h"

void TimerManager::add(Timer& timer) {
    _timers.push_back(&timer);
    std::sort(_timers.begin(), _timers.end());
}

//void TimerManager::remove(Timer& timer) {
//    _timers.erase(std::remove(_timers.begin(), _timers.end(), timer), _timers.end());
//}

void TimerManager::tick(unsigned long milli) {
    while (milli < _timers.front()->nextTickAt()) {
        Timer* timer = _timers.front();
        _timers.pop_front();
        if (timer->action(milli)) {
            add(*timer);
        }
    }
}

deque<Timer*> TimerManager::timers() {
    return _timers;
}
