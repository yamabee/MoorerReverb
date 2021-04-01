/*
  ==============================================================================

    Moorer(2).h
    Created: 25 Mar 2021 2:43:16pm
    Author:  Braden Carei

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Moorer
{
public:
    
    
    Moorer();
    ~Moorer();
    
    const int Fs = 48000;
    const float combDelay[4]={.0437*48000,.0411*48000,.0371*48000,.0297*48000};
    const float cDGain[4] = {-.9,.9, -.9,.9};
    const float apfGain[2] = {.707,.707};
    const float apfDelay[2] = {.0050*48000, .0017*48000};
    
    //getters
    float getCombDelay(const int elem);
    float getAllpassDelay(const int elem);
    float getAllpassGain(const int elem);
    
    //setters
    void setCombGain(const float percent);
    void setAllpassGain(const int elem, const float g);
    void setAllpassDelay(const int elem, const int Fs, const float d);
    
    //main methods
    float processSample(const float in, const int channel);

private:

    FBCF *combs[4];
    APF *allpasses[2];
    DelayTapLine *er[1];

 
};