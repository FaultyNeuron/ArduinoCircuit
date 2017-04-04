//
// Created by Neuron on 03/04/2017.
//

#ifndef BASICS_LEDROW_H
#define BASICS_LEDROW_H

#include "Led.h"
#include <StandardCplusplus.h>
#include <vector>
using namespace std;

class LedRow : public Component{
public:
    LedRow(uint8_t *pins, int pinCount);
    ~LedRow();

    Led& getLed(int index);
    void addLed(uint8_t pin);
    void displayBinaryNumber(unsigned int number);
    void lightSingleLed(int index);
    unsigned int getLedCount();

private:
    vector<Led*> _leds;
    void _addLed(Led& led);
};


#endif //BASICS_LEDROW_H
