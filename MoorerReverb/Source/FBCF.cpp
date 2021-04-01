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


float FBCF::processSample(float x, int channel){
    float w = frac.processSample(x, channel);
    float fb = x + -gain * w;
    float y = fb;
    
    return y;
    
}
