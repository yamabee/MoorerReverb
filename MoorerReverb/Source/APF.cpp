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

APF::APF(float newFs, float newDelaySamples, float newSpeed, float newDepth, float newGain) {
    setFs(newFs);
    setDelaySamples(newDelaySamples);
    setGain(newGain);
}

void APF::setFs(float newFs){
    Fs = newFs;
    frac.setFs(Fs);
}

void APF::setDelaySamples(float newDelaySamples){
    delaySamples = newDelaySamples;
    frac.setDelaySamples(delaySamples);
}

void APF::setSpeed(float newSpeed){
    speed = newSpeed;
    frac.setSpeed(speed);
}

void APF::setDepth(float newDepth){
    depth = newDepth;
    frac.setDepth(depth);
}

void APF::setGain(float newGain){
    gain = newGain;
}

float APF::getDelaySamples(){
    return delaySamples;
}

float APF::getGain() {
    return gain;
}

float APF::processSample(float x, int chan){

    float w = frac.processSample(x, chan);
    float v = x + (-gain * w);
    memory = v;
    float y = (gain * v) + w;
    
    return y;
    
}





