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

    float processSample(float x, int channel);
    
    void setGain(float newGain);
    void setFs(float newFs);
    void setDelaySamples(float newDelay);
    void setSpeed(float newSpeed);
    void setDepth(float newDepth);



private:
    //create instance of fractional delay in private
    FractionalDelay frac;
    
    float gain =-0.7f;
    int Fs =  48000.f;
    float delay = 0.f;
    float speed =0.f;
    float depth = 5.f;
    
    float fb = 0.f;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FBCF)
};
