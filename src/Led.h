//
// Created by Neuron on 03/04/2017.
//

#ifndef BASICS_LED_H
#define BASICS_LED_H

#include "Component.h"

class Led : public Component{
public:
    Led(uint8_t _pin);

    void toggle();
    void turnOn(bool on);

private:
    uint8_t _pin;
    bool _isOn = false;
};


#endif //BASICS_LED_H
