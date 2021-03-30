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
FBCF::FBCF()
{
///////////////////////////////////////////////// CODE FROM ERIN
//    function o = LP_FBCF(Fs,dSamples,rate,amp,g)
//                o.md = ModDelaySamples(Fs,dSamples+amp,dSamples-amp,rate);
//                setSampleRate(o,Fs);
//                setDelay(o,dSamples,amp)
//                setRate(o,rate);
//                setFBGain(o,g);
//
//            end
///////////////////////////////////////////////
}

FBCF::~FBCF()
{
}

void FBCF::processSignal(float *signal, const int numSamples, const int c)
{
    for (int n=0; n<numSamples; n++){
        float x = *signal; //get value at memory location
        x = processSample(x,c);
        *signal = x;
        signal++;
        
    }
}

float FBCF::processSample(float x, int c){
    
    int delayIndex = writeIndex[c] - delaySamples;
    
    if (delayIndex < 0){
        delayIndex += BUFFERSIZE;
    }
    
    float d = filter.processSample(w[c][delayIndex], c);
    
/////////////////////////////////////////////// CODE FROM ERIN
    o.sample = o.md.processSample(x + o.g * (0.5 * o.sample + 0.5 * o.fbLPF));
/////////////////////////////////////////////////////
    float y = x.md.processSample(x + x.g * (0.5f * x.sample + 0.5f * o.fbLPF));
    
    float y = x + 0.7f * d;
    
    // Feed-forward
    //w[c][index[c]] = x;
    
    // Feed-back
    w[c][writeIndex[c]] = y;
    
    writeIndex[c]++;
    if (writeIndex[c] >= BUFFERSIZE){
        writeIndex[c] = 0;
    }
    
    return y;
    
}


void FBCF::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("FBCF", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void FBCF::resized()
{
}
