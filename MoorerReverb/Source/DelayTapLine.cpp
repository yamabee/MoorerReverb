/*
  ==============================================================================

    DelayTapLine.cpp
    Created: 25 Mar 2021 2:19:57pm
    Author:  John Rupsch

  ==============================================================================
*/

#include "DelayTapLine.h"
#include <iostream>
#include <cmath>
using namespace std;

void DelayTapLine::setFs(float newFs){
    Fs = newFs;
}

void DelayTapLine::setParameters(float delayTimesSamp, float gainER, float Fs){
    
    float delayTimesSamp[19] = {round(Fs*0.f), round(Fs*0.01277f), round(Fs*0.01283f), round(Fs*0.01293f), round(Fs*0.01333f), round(Fs*0.01566f), round(Fs*0.02404f), round(Fs*0.02679f), round(Fs*0.02731f), round(Fs*0.02737f), round(Fs*0.02914f), round(Fs*0.02920f), round(Fs*0.02981f), round(Fs*0.03389f), round(Fs*0.04518f), round(Fs*0.04522f), round(Fs*0.04527f), round(Fs*0.05452f), round(Fs*0.06958f)};
    
    float gainER[19] = {1, 0.1526, -0.4097, 0.2984, 0.1553, 0.1442,-0.3124, -0.4176, -0.9391, 0.6926, -0.5787, 0.5782, 0.4206, 0.3958, 0.3450, -0.5361, 0.417, 0.1948, 0.1548};
    
    

    
    
    

    
    
    
}






















//void DelayTapLine::splitSignal(float * leftChannel, float * rightChannel, const int N){
//    for (int n = 0; n < N; n++){
//        float L = leftChannel[n];
//        float R = rightChannel[n];
//    }
//}
//void DelayTapLine::splitSignal(juce::AudioBuffer<float>& buffer){
//    float * leftChannel = buffer.getWritePointer(0);
//    float * rightChannel = buffer.getWritePointer(1);
//    int N = buffer.getNumSamples();
//    splitSignal(leftChannel, rightChannel, N);
//};
