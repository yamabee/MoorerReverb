/*
  ==============================================================================

    EarlyReflections.h
    Created: 31 Mar 2021 7:48:59pm
    Author:  Erin Lindsey Yamabe

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "FractionalDelay.hpp"

class EarlyReflections {
    
public:
    EarlyReflections();
    ~EarlyReflections();
    
    void setSampleRate(float newFs);
    
    void setDelayTimeSamples();
    void setGain();
    
    void createIndex();
    
    float processSample(float x, int chan);
    
private:
    float Fs = 48000.f;
    
    FractionalDelay *frac[19];
    
//    float buf[48000][2] = {0.f};
//    float bufferLength = 48000.f;
//
//    int wIndex[2] = {48000,48000};
//    int rIndex[19][2];
    
    float delayTimeSamples[19];
    float gain[19];
    
    float y[2] = {0.f,0.f};
    
};
