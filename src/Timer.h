//
// Created by Neuron on 03/04/2017.
//

#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H


class Timer {
public:
    virtual bool action(unsigned long millis) = 0;
    virtual unsigned long nextTickAt() const = 0;
    bool operator < (const Timer& other) const;

private:
};


#endif //BASIC_TIMER_H
