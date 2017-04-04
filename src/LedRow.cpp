//
// Created by Neuron on 03/04/2017.
//

#include "LedRow.h"


//void setup(void)
//{
//    Serial.begin(57600);
//
//    strings.push_back("Hello,");
//    strings.push_back("world!");
//    copy(strings.begin(),strings.end(),ostream_iterator<string>(cout," "));
//    cout << endl;


void LedRow::displayBinaryNumber(unsigned int number) {
    for (unsigned int i = getLedCount() - 1; i >= 0; ++i) {
        getLed(i).turnOn(number % 2 == 1);
        number /= 2;
    }
}


Led& LedRow::getLed(unsigned int index) {
    return _leds[index];
}

void LedRow::_addLed(Led& led) {
    _leds.push_back(led);
}

LedRow::LedRow(uint8_t* pins, int pinCount) {
    for (int i = 0; i < pinCount; i++) {
        addLed(pins[i]);
    }
}

void LedRow::addLed(uint8_t pin) {
    _addLed(*new Led(pin));
}

LedRow::~LedRow() {
    for (int i = 0; i < getLedCount(); i++) {
        delete _leds[i];
    }
}

unsigned int LedRow::getLedCount() {
    return _leds.size();
}
