//
// Created by Neuron on 04/04/2017.
//

#ifndef BASIC_NIGHTRIDERANIMATION_H
#define BASIC_NIGHTRIDERANIMATION_H

#include "Animation.h"
#include "LedRow.h"

class NightRiderAnimation : public Animation{
public:
    NightRiderAnimation(unsigned long animationDelay, unsigned long milli, LedRow &ledRow);
    virtual void tick(unsigned long millis) override;

    virtual void nextFrame() override;
private:
    LedRow& _ledRow;
    bool _up = true;
    int _currentLed = 0;

};


#endif //BASIC_NIGHTRIDERANIMATION_H
