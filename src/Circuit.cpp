//
// Created by Neuron on 03/04/2017.
//

#include "Circuit.h"

void Circuit::tick() {
    tick(millis());
}

void Circuit::tick(unsigned long  milli) {
    for (auto component : _components) {
        component.tick(milli);
    }
}

void Circuit::addComponent(Component &component) {
    _components.push_back(component);
}
