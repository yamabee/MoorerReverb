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


float DelayTapLine::earlyRef(float x, float Fs, float delayTimesSamp, float gainER){
    // setFs
    // setParameters
    // createIndex
    return x;
}

void DelayTapLine::setFs(float newFs){
    Fs = newFs;
}

//void DelayTapLine::setParameters(vector<float> delayTimesSamp, vector<float> gainER){
    
//    vector<float> delayTimesSamp = {round(Fs*0.f), round(Fs*0.01277f), round(Fs*0.01283f), round(Fs*0.01293f), round(Fs*0.01333f), round(Fs*0.01566f), round(Fs*0.02404f), round(Fs*0.02679f), round(Fs*0.02731f), round(Fs*0.02737f), round(Fs*0.02914f), round(Fs*0.02920f), round(Fs*0.02981f), round(Fs*0.03389f), round(Fs*0.04518f), round(Fs*0.04522f), round(Fs*0.04527f), round(Fs*0.05452f), round(Fs*0.06958f)};
    
//    vector<float> delayTimesSamp(round(Fs*0.f), round(Fs*0.01277f), round(Fs*0.01283f), round(Fs*0.01293f), round(Fs*0.01333f), round(Fs*0.01566f), round(Fs*0.02404f), round(Fs*0.02679f), round(Fs*0.02731f), round(Fs*0.02737f), round(Fs*0.02914f), round(Fs*0.02920f), round(Fs*0.02981f), round(Fs*0.03389f), round(Fs*0.04518f), round(Fs*0.04522f), round(Fs*0.04527f), round(Fs*0.05452f), round(Fs*0.06958f));
    
void DelayTapLine::setParameters(){
    
    delayTimesSamp[0] = 0.f;
    delayTimesSamp[1] = round(Fs*0.01277f);
    delayTimesSamp[2] = round(Fs*0.01283f);
    delayTimesSamp[3] = round(Fs*0.01293f);
    delayTimesSamp[4] = round(Fs*0.01333f);
    delayTimesSamp[5] = round(Fs*0.01566f);
    delayTimesSamp[6] = round(Fs*0.02404f);
    delayTimesSamp[7] = round(Fs*0.02679f);
    delayTimesSamp[8] = round(Fs*0.02731f);
    delayTimesSamp[9] = round(Fs*0.02737f);
    delayTimesSamp[10] = round(Fs*0.02914f);
    delayTimesSamp[11] = round(Fs*0.02920f);
    delayTimesSamp[12] = round(Fs*0.02981f);
    delayTimesSamp[13] = round(Fs*0.03389f);
    delayTimesSamp[14] = round(Fs*0.04518f);
    delayTimesSamp[15] = round(Fs*0.04522f);
    delayTimesSamp[16] = round(Fs*0.04527f);
    delayTimesSamp[17] = round(Fs*0.05452f);
    delayTimesSamp[18] = round(Fs*0.06958f);

    gainER[0] = 1.f;
    gainER[1] = 0.1526f;
    gainER[2] = -0.4097f;
    gainER[3] = 0.2984f;
    gainER[4] = 0.1553f;
    gainER[5] = 0.1442f;
    gainER[6] = -0.3124f;
    gainER[7] = -0.4176f;
    gainER[8] = -0.9391f;
    gainER[9] = 0.6926f;
    gainER[10] = -0.5787f;
    gainER[11] = 0.5782f;
    gainER[12] = 0.4206f;
    gainER[13] = 0.3958f;
    gainER[14] = 0.3450f;
    gainER[15] = -0.5361f;
    gainER[16] = 0.417f;
    gainER[17] = 0.1948f;
    gainER[18] = 0.1548f;
    
//    delayTimesMS[0] = 0.f;
//    delayTimesMS[1] = round(Fs*0.01277f);
//    delayTimesMS[2] = round(Fs*0.01283f);
//    delayTimesMS[3] = round(Fs*0.01293f);
//    delayTimesMS[4] = round(Fs*0.01333f);
//    delayTimesMS[5] = round(Fs*0.01566f);
//    delayTimesMS[6] = round(Fs*0.02404f);
//    delayTimesMS[7] = round(Fs*0.02679f);
//    delayTimesMS[8] = round(Fs*0.02731f);
//    delayTimesMS[9] = round(Fs*0.02737f);
//    delayTimesMS[10] = round(Fs*0.02914f);
//    delayTimesMS[11] = round(Fs*0.02920f);
//    delayTimesMS[12] = round(Fs*0.02981f);
//    delayTimesMS[13] = round(Fs*0.03389f);
//    delayTimesMS[14] = round(Fs*0.04518f);
//    delayTimesMS[15] = round(Fs*0.04522f);
//    delayTimesMS[16] = round(Fs*0.04527f);
//    delayTimesMS[17] = round(Fs*0.05452f);
//    delayTimesMS[18] = round(Fs*0.06958f);
// / / / / / / / / / / So you could do: delayTimesSamp[3] = round(Fs*delayTimesMS[3];
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    gainER = {1.f, 0.1526f, -0.4097f, 0.2984f, 0.1553f, 0.1442f,-0.3124f, -0.4176f, -0.9391f, 0.6926f, -0.5787f, 0.5782f, 0.4206f, 0.3958f, 0.3450f, -0.5361f, 0.417f, 0.1948f, 0.1548f};
    
//    float delayTimesSamp[19] = {round(Fs*0.f), round(Fs*0.01277f), round(Fs*0.01283f), round(Fs*0.01293f), round(Fs*0.01333f), round(Fs*0.01566f), round(Fs*0.02404f), round(Fs*0.02679f), round(Fs*0.02731f), round(Fs*0.02737f), round(Fs*0.02914f), round(Fs*0.02920f), round(Fs*0.02981f), round(Fs*0.03389f), round(Fs*0.04518f), round(Fs*0.04522f), round(Fs*0.04527f), round(Fs*0.05452f), round(Fs*0.06958f)};
    
//    vector<float> gainER = {1.f, 0.1526f, -0.4097f, 0.2984f, 0.1553f, 0.1442f,-0.3124f, -0.4176f, -0.9391f, 0.6926f, -0.5787f, 0.5782f, 0.4206f, 0.3958f, 0.3450f, -0.5361f, 0.417f, 0.1948f, 0.1548f};
    
//    float tgainER[19] = {1.f, 0.1526f, -0.4097f, 0.2984f, 0.1553f, 0.1442f,-0.3124f, -0.4176f, -0.9391f, 0.6926f, -0.5787f, 0.5782f, 0.4206f, 0.3958f, 0.3450f, -0.5361f, 0.417f, 0.1948f, 0.1548f};
   
    
    
    // MAIN PROCESSING BLOCK //
float DelayTapLine::process(float o, float input){
     //float N = sizeof(float input);
    DelayTapLine.processSample();
    

    
    
    

    
    
    
}


void DelayTapLine::processSample(const int N, float x){
    float y = 0;
    o.buf(o.wIndex,1) = x;
    
    for (int i = 0; i < 19; i++){
        y = y + o.gainER[i] * o.buf(o.rIndex[i]);
        
        o.rIndex[i] = o.rIndex[i]+1;
        
        if (o.rIndex[i] > o.M){
            o.rIndex[i] = o.Index[i] - o.M;
        }
    }
    o.wIndex = o.wIndex + 1;
    
    if (o.wIndex > o.M){
        o.wIndex = o.wIndex - o.M;
    }
    
}

void DelayTapLine::createIndex(){
    for (int j = 0; j < 19; j++){
        o.rIndex[j] = o.wIndex - o.delayTimesSamp;
        
        if (o.rIndex[j] > o.M){
            o.rIndex[j] = o.rIndex[j] - o.M;
        }
    }
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
