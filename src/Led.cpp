//
// Created by Neuron on 03/04/2017.
//

#include "Led.h"


void Led::toggle() {
    _isOn = !_isOn;
    digitalWrite(_pin, _isOn ? HIGH : LOW);
}

void Led::turnOn(bool on) {
    if (on != _isOn) {
        toggle();
    }
}

Led::Led(uint8_t _pin) : _pin(_pin) {}
