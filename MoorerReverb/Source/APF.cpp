/*
  ==============================================================================

    APF.cpp
    Created: 25 Mar 2021 2:12:49pm
    Author:  Mitchell Elliott

  ==============================================================================
*/

#include "APF.h"

APF::APF(){
    
}

APF::APF(float delay, float speed, float fb){
    
}

float APF::processSample(float x, int c){

    float w = x + fb;
    float v = frac.processSample(w,c);
    fb = v;
    float y = w + v;
    
    return y;
}

void APF::setDelaySamples(float delay){
  
    frac.setDelaySamples(delay);
    
}

void APF::setSpeed(float speed){
 
    frac.setSpeed(speed);
    
}
