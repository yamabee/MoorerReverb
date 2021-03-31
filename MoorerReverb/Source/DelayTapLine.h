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
    

    
    
    float earlyRef(float x, float Fs, float delayTimesSamp, float gainER);

    float process(float o, float input);
    
    void processSample(const int N, float x);
    // ? float? ^^^
    
    
    
    
    // Setters and Getters------------------------------------------------------------------
    void setFs(float newFs);
    
    void setParameters();
    
    void createIndex(float o);
    // -------------------------------------------------------------------------------------
    
    
    
    
    
    
private:
    
    
protected:
    float Fs = 48000.f;
    float M = 48000.f;
//    static const int BUFFERSIZE = 96000;
    float buf[48000] = {0.f};
    float wIndex[48000] = {0.f};
    float rIndex[19] = {0.f};
    
    
    float delayTimesSamp[19];
    float gainER[19];
    //float delayTimesMS[19];
    
    
    
    
    
    
    
//    struct myParameters{
//        float delayTimesSamp[19] = {round(Fs*0.f), round(Fs*0.01277f), round(Fs*0.01283f), round(Fs*0.01293f), round(Fs*0.01333f), round(Fs*0.01566f), round(Fs*0.02404f), round(Fs*0.02679f), round(Fs*0.02731f), round(Fs*0.02737f), round(Fs*0.02914f), round(Fs*0.02920f), round(Fs*0.02981f), round(Fs*0.03389f), round(Fs*0.04518f), round(Fs*0.04522f), round(Fs*0.04527f), round(Fs*0.05452f), round(Fs*0.06958f)};
//
//        float gainER[19] = {1, 0.1526, -0.4097, 0.2984, 0.1553, 0.1442,-0.3124, -0.4176, -0.9391, 0.6926, -0.5787, 0.5782, 0.4206, 0.3958, 0.3450, -0.5361, 0.417, 0.1948, 0.1548});
//    };
//
//    myParameters myParams;
    
    
//    float delayTimesSamp{19} = {Fs*0;Fs*0.01277;Fs*0.01283;Fs*0.01293;Fs*0.01333;Fs*0.01566;Fs*0.02404;Fs*0.02679;Fs*0.02731;Fs*0.02737;Fs*0.02914;Fs*0.02920;Fs*0.02981;Fs*0.03389;Fs*0.04518;Fs*0.04522;Fs*0.04527;Fs*0.05452;Fs*0.06958};
//
//    float gainER{19} = {1; 0.1526; -0.4097; 0.2984; 0.1553; 0.1442;...
//                -0.3124; -0.4176; -0.9391; 0.6926; -0.5787; 0.5782;...
//                0.4206; 0.3958; 0.3450; -0.5361; 0.417; 0.1948; 0.1548};
    
    
    
    
    
//public:
//    void setParams(myParameters params){
//        myParams.delayTimesSamp = params.delayTimesSamp;
//        myParams.gainER = params.gainER;
        
        
        
//    }
    
};
