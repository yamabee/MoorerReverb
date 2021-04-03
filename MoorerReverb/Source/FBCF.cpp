/*
  ==============================================================================

    FBCF.cpp
    Created: 25 Mar 2021 2:23:59pm
    Author:  Emily Pikul

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FBCF.h"

//==============================================================================
FBCF::FBCF(){}

FBCF::FBCF(float newFs, float newDelaySamples, float newSpeed, float newDepth, float newGain) {
    setSampleRate(newFs);
    setDelaySamples(newDelaySamples);
    setSpeed(newSpeed);
    setDepth(newDepth);
    setGain(newGain);
    
}

FBCF::~FBCF()
{
}

void FBCF::setGain(float newGain){
    gain=newGain;
     
}

void FBCF::setSampleRate(float newFs){
    Fs = newFs;
    frac.setFs(Fs);
}

void FBCF::setDelaySamples(float newDelaySamples){
    delaySamples = newDelaySamples;
    frac.setDelaySamples(delaySamples);
}

void FBCF::setSpeed(float newSpeed){
    speed = newSpeed;
    frac.setSpeed(speed);
}

void FBCF::setDepth(float newDepth){
    depth = newDepth;
    frac.setDepth(depth);
    
}

float FBCF::getDelaySamples() {
    return delaySamples;
}

float FBCF::getGain() {
    return gain;
}


float FBCF::processSample(float x, int channel){
    memory = frac.processSample(x + gain * (0.5*memory + 0.5*fbLPF), channel);
    float y = memory;
    fbLPF = y;
    
//    float fb = x + -gain * w;
//    float y = fb;
    
    return y;
    
}
