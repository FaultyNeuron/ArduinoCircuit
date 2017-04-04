//
// Created by Neuron on 03/04/2017.
//

#include "Button.h"

Button::Button(uint8_t pin) : Button(pin, DEFAULT_HISTORY_LENGTH, DEFAULT_HISTORY_DELAY) {

}

Button::Button(uint8_t pin, unsigned int historyLength, unsigned int historyDelay, unsigned long milli) : _pin(pin){
    _historyLength = historyLength;
    _pressedHistory = new bool[_historyLength]();
    addPrepareTimer(*new ButtonTimer(historyDelay, milli, *this));
}

void Button::addOnPressListener(const ActionListener &listener) {
    _onPressListeners.push_back(listener);
}

void Button::removeOnPressListener(const ActionListener &listener) {
    _onPressListeners.erase(std::remove(_onPressListeners.begin(), _onPressListeners.end(), listener), _onPressListeners.end());
}

void Button::addOnReleaseListener(const ActionListener &listener) {
    _onReleaseListeners.push_back(listener);
}

void Button::removeOnReleaseListener(const ActionListener &listener) {
    _onReleaseListeners.erase(std::remove(_onReleaseListeners.begin(),_onReleaseListeners.end(), listener),
                              _onReleaseListeners.end());
}

void Button::tick(unsigned long millis) {
    Component::tick(millis);
    if (_notifyListeners) {
        if (_isPressed) {
            for (auto &onPressListener : _onPressListeners){
                onPressListener.action();
            }
        } else {
            for (auto &onReleaseListener : _onReleaseListeners){
                onReleaseListener.action();
            }
        }
    }
}


Button::ButtonTimer::ButtonTimer(unsigned long timerDelay, unsigned long milli, Button &button) :
        PeriodicTimer(timerDelay, milli), button(button) {

}

bool Button::ButtonTimer::action(unsigned long millis) {
    bool wasPressed = button._isPressed;
    int counter = 0;
    button._pressedHistory[button._historyIndex] = digitalRead(button._pin) == HIGH;
    for (int i = 0; i < button._historyLength; ++i) {
        counter += button._pressedHistory[i] ? 1 : 0;
    }
    button._isPressed = counter > button._historyLength / 2.;
    if (button._isPressed != wasPressed) {
        button._notifyListeners = true;
    }
    button._historyIndex = (button._historyIndex + 1) % button._historyLength;
    return PeriodicTimer::action(millis);
}
