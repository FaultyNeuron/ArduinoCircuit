//
// Created by Neuron on 03/04/2017.
//

#include "Circuit.h"
#include <Arduino.h>

void Circuit::tick() {
    tick(millis());
}

void Circuit::tick(unsigned long  milli) {
    for (auto const &component : _components) {
        component->prepare(milli);
    }
    for (auto const &component : _components) {
        component->tick(milli);
    }
    for (auto const &animation : _animations) {
        animation->tick(milli);
    }
}

void Circuit::addComponent(Component &component) {
    _components.push_back(&component);
}

void Circuit::addAnimation(Animation &animation) {
    _animations.push_back(&animation);
}
