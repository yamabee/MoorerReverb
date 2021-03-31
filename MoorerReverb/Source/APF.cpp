/*
  ==============================================================================

    APF.cpp
    Created: 25 Mar 2021 2:12:49pm
    Author:  Mitchell Elliott

  ==============================================================================
*/

#include "APF.h"

APF::APF(){
    
}

void APF::setFs(int newFs){
    Fs = newFs;
    frac.setFs(Fs);
}

void APF::setDelaySamples(float newDelay){
    delay = newDelay;
    frac.setDelaySamples(delay);
}

void APF::setSpeed(float newSpeed){
    speed = newSpeed;
    frac.setSpeed(speed);
}

void APF::setDepth(float newDepth){
    depth = newDepth;
    frac.setDepth(depth);
}

void APF::setGain(float newG){
    g = newG;
}

float APF::processSample(float x, int c){

    float w = frac.processSample(x, c);
    float v = x + (-g * w);
    x = v;
    float y = (g * v) + w;
    
    
    return y;
    
}





