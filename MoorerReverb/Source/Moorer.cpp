/*
  ==============================================================================

    Moorer.cpp
    Created: 25 Mar 2021 2:43:16pm
    Author:  Braden Carei

  ==============================================================================
*/

#include "Moorer.h"

Moorer::Moorer(){
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    combs[0] = new FBCF();
    combs[1] = new FBCF();
    combs[2] = new FBCF();
    combs[3] = new FBCF();

    
    allpass[0] = new APF();
    allpass[1] = new APF();
    
    er[0] = new EarlyReflections();
}

Moorer::~Moorer(){
    delete combs[0];
    delete combs[1];
    delete combs[2];
    delete combs[3];
    
    delete combs[0];
    delete combs[1];
}

//float Moorer::getCombDelay(const int elem) {
//    return combs[elem]->getDelaySamples();
//
//}

//float Moorer::getAllpassDelay(const int elem){
//    return allpass[elem]->getDelaySamples();
//
//}

//float Moorer::getAllpassGain(const int elem){
//    return allpass[elem]->getGain();
//
//}

void Moorer::setSampleRate(float newFs) {
    Fs = newFs;
    for (int i = 0; i < 4; i++) {
        combs[i]->setSampleRate(Fs);
    }
    
    for (int j = 0; j < 2; j++) {
        allpass[j]->setSampleRate(Fs);
    }
    
    er[0]->setSampleRate(Fs);
    
}

void Moorer::setCombDelay(const int elem, const float combDelay) {
    for (int i = 0; i < 4 ; i++) {
        combs[i]->setDelaySamples(combDelay);
    }
}
void Moorer::setAllpassDelay(const int elem, const float apfDelay) {
    for (int j = 0; j < 2 ; j++) {
        allpass[j]->setDelaySamples(apfDelay);
    }
}

void Moorer::setCombGain(const float newGainPercent){
    cfGainPercent = newGainPercent;
    for(int i = 0; i < 4; i++){
        
            float gain = 0.0f;
            gain = combs[i]->getGain()*cfGainPercent;
            combs[i]->setGain(gain);
        }
}

void Moorer::setAllpassGain(float newGain) {
    apGainPercent = newGain;
    for (int i = 0; i < 2; ++i) {
        float gain = 0.0f;
        gain = allpass[i] ->getGain()*apGainPercent;
        allpass[i]->setGain(gain);
    }
}

void Moorer::setModulation(float newModulation) {
    modulation = newModulation;
    float rateValue = 0.6f;
    for(int i = 0; i < 4; i++){
        combs[i]->setDepth(modulation);
        combs[i]-> setSpeed(rateValue);
        rateValue = rateValue + 0.12;
        }
    for (int i = 0; i < 2; ++i) {
        allpass[i]->setDepth(modulation);
        allpass[i]->setSpeed(rateValue);
        rateValue =rateValue + 0.12;
    }
}

//void Moorer::setAllpassGain(const int elem, const float g){
//    allpass[elem]->setGain(g);
//
//}

//void Moorer::setAllpassDelay(const int elem, const int Fs, const float d) {
//    allpass[elem]->setFs(Fs);
//    allpass[elem]->setDelaySamples(d);
//
//}

float Moorer::processSample(const float x, const int channel){
    float combOut = 0.0f;
    float apf1Out = 0.0f;
    float apf2Out = 0.0f;
    float ers = 0.0f;
    float tapOut = 0.0f;
    
    //early reflect
    ers = er[0]->processSample(x,channel);
           
    tapOut = ers;
    
    //combs take output from early reflect generator
    for(int i = 0; i < 4; i++){
        combOut += combs[i]->processSample(tapOut * 0.25f,channel);
    }
    
    //output of combs fed to all pass
    apf1Out = allpass[0]->processSample(combOut,channel);
    apf2Out = allpass[1]->processSample(apf1Out,channel);
    
    return apf2Out;
    
}
