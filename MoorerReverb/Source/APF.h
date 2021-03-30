/*
  ==============================================================================

    APF.h
    Created: 25 Mar 2021 2:12:49pm
    Author:  Mitchell Elliott

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#pragma once

// Class for implimenting colorless reverb using an
// All pass filter
class APF{
    
public:
    APF();
    
    APF(float delay, float speed, float fb);
    
    float processSample(float x, int c);
    
    void setDelaySamples(float delay);
    void setSpeed(float speed);
    
    
private:
    FractionalDelay frac;
    
    int Fs = 48000;
    int sampleStart = 0;
    float speed = 0.9;
    float fb = 0.0f;
    
};
