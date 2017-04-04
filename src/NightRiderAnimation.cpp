//
// Created by Neuron on 04/04/2017.
//

#include "NightRiderAnimation.h"

void NightRiderAnimation::tick(unsigned long millis) {
    Animation::tick(millis);
}

NightRiderAnimation::NightRiderAnimation(unsigned long animationDelay, unsigned long milli, LedRow &ledRow) :
        Animation(animationDelay, milli), _ledRow(ledRow) {}

void NightRiderAnimation::nextFrame() {
    _ledRow.lightSingleLed(_currentLed);
    _currentLed = _currentLed + _up ? 1 : -1;
    if (_currentLed == _ledRow.getLedCount() || _currentLed == -1) {
        _currentLed = !_currentLed;
        _currentLed = _currentLed + _up ? 2 : -2;
    }
}
