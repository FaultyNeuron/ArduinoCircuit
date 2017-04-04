//
// Created by Neuron on 03/04/2017.
//

#ifndef BASIC_BUTTON_H
#define BASIC_BUTTON_H

#define DEFAULT_HISTORY_LENGTH 10
#define DEFAULT_HISTORY_DELAY 3

#include "Arduino.h"
#include "Component.h"
#include "ActionListener.h"
#include <vector>
using namespace std;

class Button : public Component {
//    friend class ButtonTimer;
public:
    Button(uint8_t pin);
    Button(uint8_t pin, unsigned int historyLength, unsigned int historyDelay, unsigned long milli);
    void addOnPressListener(const ActionListener &listener);
    void removeOnPressListener(const ActionListener &listener);
    void addOnReleaseListener(const ActionListener &listener);
    void removeOnReleaseListener(const ActionListener &listener);
    void tick(unsigned long millis);
    bool isPressed() {return _isPressed;}

private:
    uint8_t _pin;
    int _historyLength;
    bool* _pressedHistory;
    vector<ActionListener> _onPressListeners;
    vector<ActionListener> _onReleaseListeners;
    int _historyIndex = 0;
    bool _isPressed = false;
    bool _notifyListeners = false;

    class ButtonTimer : public PeriodicTimer {
    public:
        ButtonTimer(unsigned long timerDelay, unsigned long milli, Button &button);
        virtual bool action(unsigned long millis) override;

    private:
        Button& button;
    };
};


#endif //BASIC_BUTTON_H
