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
    
    float processSample(float x, int c);
    
    //call to update delay for APF in Moorer Reverb
    void setDelaySamples(float newDelay);
    
    //call to update speed for APF in Moorer Reverb
    void setSpeed(float newSpeed);
    
    void setDepth(float newDepth);
    
    void setFs(int newFs);
    
    void setGain(float g);
    
private:
    
    int Fs = 48000;
    float delay = 5.0f;
    float speed = 0.9f;
    float depth = 0.8f;
    float g = 0.0f;
    
    FractionalDelay frac;
    
};
