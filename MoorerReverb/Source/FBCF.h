/*
  ==============================================================================

    FBCF.h
    Created: 25 Mar 2021 2:23:59pm
    Author:  Emily Pikul

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
//==============================================================================
/*
*/
class FBCF  : public juce::Component
{
public:
    FBCF();
    
    ~FBCF() override;
    
    void setGain(float newGain);
    void setSampleRate(float newFs);
    void setDelaySamples(float newDelaySamples);
    void setSpeed(float newSpeed);
    void setDepth(float newDepth);

    float processSample(float x, int channel);

private:
    //create instance of fractional delay in private
    FractionalDelay frac;
    
    float Fs =  48000.f;
    
    float gain = -0.7f;
    float delaySamples = 0.f;
    float speed = 0.f;
    float depth = 5.f;
    
    float fb = 0.f;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FBCF)
};
