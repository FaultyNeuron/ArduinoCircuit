//
// Created by Neuron on 03/04/2017.
//

#ifndef BASICS_CIRCUIT_H
#define BASICS_CIRCUIT_H
#include "Component.h"
#include "Animation.h"
#include <StandardCplusplus.h>
#include <vector>
using namespace std;

class Circuit : public Component{
public:
    void tick(unsigned long millis);
    void tick();
    void addComponent(Component& component);
    void addAnimation(Animation& animation);
private:
    vector<Component*> _components;
    vector<Animation*> _animations;
};


#endif //BASICS_CIRCUIT_H
