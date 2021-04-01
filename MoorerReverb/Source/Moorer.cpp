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

Moorer::~Moorer(){}

float Moorer::getCombDelay(const int elem) {
    return combs[elem]->getDelaySamples();
    
}

float Moorer::getAllpassDelay(const int elem){
    return allpass[elem]->getDelaySamples();
    
}

float Moorer::getAllpassGain(const int elem){
    return allpass[elem]->getGain();
    
}

void Moorer::setSampleRate(float newFs) {
    Fs = newFs;
    
}

void Moorer::setCombGain(const float percent){
    
    for(int i = 0; i < 4; i++){
        
            float gain = 0.0f;
            gain = combs[i]->getGain()*percent;
            combs[i]->setGain(gain);
        }
}

void Moorer::setAllpassGain(const int elem, const float g){
    allpass[elem]->setGain(g);
    
}

void Moorer::setAllpassDelay(const int elem, const int Fs, const float d) {
    allpass[elem]->setFs(Fs);
    allpass[elem]->setDelaySamples(d);
    
}

float Moorer::processSample(const float in, const int channel){
    float combOut = 0.0f;
    float apf1Out = 0.0f;
    float apf2Out = 0.0f;
    float ers = 0.0f;
    float tapOut = 0.0f;
    
    //early reflect
    ers = er[0]->processSample(in,channel);
           
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
