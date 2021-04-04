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
    setSampleRate(newFs);
    setDelaySamples(newDelaySamples);
    setGain(newGain);
}

void APF::setSampleRate(float newFs){
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

//float APF::getDelaySamples(){
//    return delaySamples;
//}

float APF::getGain() {
    return gain;
}

float APF::processSample(float x, int chan){

    w[chan] = frac.processSample(memory[chan], chan);
    v[chan] = x + (-gain * w[chan]);
    memory[chan] = v[chan];
    float y = (gain * v[chan]) + w[chan];
    
    return y;
    
}





