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
    //No call constructor
    APF();
    APF(float newFs, float newDelaySamples, float newSpeed, float newDepth, float newGain);
    
    float processSample(float x, int chan);
    
    //call to update delay for APF in Moorer Reverb
    void setDelaySamples(float newDelaySamples);
    
    //call to update speed for APF in Moorer Reverb
    void setSpeed(float newSpeed);
    void setDepth(float newDepth);
    void setGain(float newGain);
    
    float getDelaySamples();
    float getGain();
    
    void setFs(float newFs);
    
private:
    
    float Fs = 48000.f;
    
    float delaySamples = 5.0f;
    float speed = 0.9f;
    float depth = 0.8f;
    float gain = 0.f;
    float memory = 0.f;
    
    FractionalDelay frac;
    
};
