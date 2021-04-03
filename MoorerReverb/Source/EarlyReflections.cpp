/*
  ==============================================================================

    EarlyReflections.cpp
    Created: 31 Mar 2021 7:48:59pm
    Author:  Erin Lindsey Yamabe

  ==============================================================================
*/

#include "EarlyReflections.h"

EarlyReflections::EarlyReflections() {
    frac[0] = new FractionalDelay();
    frac[1] = new FractionalDelay();
    frac[2] = new FractionalDelay();
    frac[3] = new FractionalDelay();
    frac[4] = new FractionalDelay();
    frac[5] = new FractionalDelay();
    frac[6] = new FractionalDelay();
    frac[7] = new FractionalDelay();
    frac[8] = new FractionalDelay();
    frac[9] = new FractionalDelay();
    frac[10] = new FractionalDelay();
    frac[11] = new FractionalDelay();
    frac[12] = new FractionalDelay();
    frac[13] = new FractionalDelay();
    frac[14] = new FractionalDelay();
    frac[15] = new FractionalDelay();
    frac[16] = new FractionalDelay();
    frac[17] = new FractionalDelay();
    frac[18] = new FractionalDelay();
    
}

EarlyReflections::~EarlyReflections() {
    delete frac[0];
    delete frac[1];
    delete frac[2];
    delete frac[3];
    delete frac[4];
    delete frac[5];
    delete frac[6];
    delete frac[7];
    delete frac[8];
    delete frac[9];
    delete frac[10];
    delete frac[11];
    delete frac[12];
    delete frac[13];
    delete frac[14];
    delete frac[15];
    delete frac[16];
    delete frac[17];
    delete frac[18];
}

void EarlyReflections::setSampleRate(float newFs) {
    Fs = newFs;
    setDelayTimeSamples();
    
}

void EarlyReflections::setDelayTimeSamples(){
    
    delayTimeSamples[0] = 0.f;
    delayTimeSamples[1] = round(Fs*0.01277f);
    delayTimeSamples[2] = round(Fs*0.01283f);
    delayTimeSamples[3] = round(Fs*0.01293f);
    delayTimeSamples[4] = round(Fs*0.01333f);
    delayTimeSamples[5] = round(Fs*0.01566f);
    delayTimeSamples[6] = round(Fs*0.02404f);
    delayTimeSamples[7] = round(Fs*0.02679f);
    delayTimeSamples[8] = round(Fs*0.02731f);
    delayTimeSamples[9] = round(Fs*0.02737f);
    delayTimeSamples[10] = round(Fs*0.02914f);
    delayTimeSamples[11] = round(Fs*0.02920f);
    delayTimeSamples[12] = round(Fs*0.02981f);
    delayTimeSamples[13] = round(Fs*0.03389f);
    delayTimeSamples[14] = round(Fs*0.04518f);
    delayTimeSamples[15] = round(Fs*0.04522f);
    delayTimeSamples[16] = round(Fs*0.04527f);
    delayTimeSamples[17] = round(Fs*0.05452f);
    delayTimeSamples[18] = round(Fs*0.06958f);
    
    for (int i = 0; i < 19; i++) {
        frac[i]->setFs(Fs);
        frac[i]->setDepth(0);
        frac[i]->setDelaySamples(delayTimeSamples[i]);
    }
}

void EarlyReflections::setGain(){
    gain[0] = 1.f;
    gain[1] = 0.1526f;
    gain[2] = -0.4097f;
    gain[3] = 0.2984f;
    gain[4] = 0.1553f;
    gain[5] = 0.1442f;
    gain[6] = -0.3124f;
    gain[7] = -0.4176f;
    gain[8] = -0.9391f;
    gain[9] = 0.6926f;
    gain[10] = -0.5787f;
    gain[11] = 0.5782f;
    gain[12] = 0.4206f;
    gain[13] = 0.3958f;
    gain[14] = 0.3450f;
    gain[15] = -0.5361f;
    gain[16] = 0.417f;
    gain[17] = 0.1948f;
    gain[18] = 0.1548f;
    
}



float EarlyReflections::processSample(float x, int chan) {

    float y = 0.f;

    for (int tap = 0; tap < 19; tap++) {
        y = y + gain[tap] * frac[tap]->processSample(x, chan);
        
    }
    
    return y;
}

