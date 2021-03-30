/*
  ==============================================================================

    DelayTapLine.h
    Created: 25 Mar 2021 2:19:57pm
    Author:  John Rupsch

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

using namespace std;

class DelayTapLine
{
public:

//    void splitSignal(float * leftChannel, float * rightChannel, const int N);
//    void splitSignal(juce::AudioBuffer<float>& buffer);
//    void staticTDL(float L, float R, const int N);
    

    
    
    float earlyRef(float Fs, float delayTimesSamp[19], float gainER);

    float process(float o, float input);
    
    void processSample(const int N, float x);
    // ? float? ^^^
    
    
    
    
    // Setters and Getters------------------------------------------------------------------
    void setFs(float newFs);
    
    void setParameters(float delayTimesSamp[19], float gainER, float Fs);
    
    void createIndex(float o);
    // -------------------------------------------------------------------------------------
    
    
    
    
private:
    
    
protected:
    float Fs = 48000.f;
    float M = 48000.f;
//    static const int BUFFERSIZE = 96000;
    float buf[48000] = {0.f};
    float wIndex = 48000.f;
    float rIndex{19} = {0.f};
    
    
//    float delayTimesSamp{19} = {Fs*0;Fs*0.01277;Fs*0.01283;Fs*0.01293;Fs*0.01333;Fs*0.01566;Fs*0.02404;Fs*0.02679;Fs*0.02731;Fs*0.02737;Fs*0.02914;Fs*0.02920;Fs*0.02981;Fs*0.03389;Fs*0.04518;Fs*0.04522;Fs*0.04527;Fs*0.05452;Fs*0.06958};
//
//    float gainER{19} = {1; 0.1526; -0.4097; 0.2984; 0.1553; 0.1442;...
//                -0.3124; -0.4176; -0.9391; 0.6926; -0.5787; 0.5782;...
//                0.4206; 0.3958; 0.3450; -0.5361; 0.417; 0.1948; 0.1548};
    
    
    
    
};
