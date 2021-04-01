/*
  ==============================================================================

    Moorer(2).cpp
    Created: 25 Mar 2021 2:43:16pm
    Author:  Braden Carei

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Moorer.h"
#include "PluginProcessor.h"

//==============================================================================
Moorer::Moorer()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    combs[0] = new FBCF()
    combs[1] = new FBCF()
    combs[2] = new FBCF()
    combs[3] = new FBCF()

    
    allpasses[0] = new APF(apfDelay1, apfGain1);
    allpasses[1] = new APF(apfDelay2, apfGain2);
    
    er[0] = new DelayTapLine();
}

Moorer::~Moorer()
{
}



float Moorer::getCombDelay(const int elem){return combs[elem]->getDelayTime();}

float Moorer::getAllpassDelay(const int elem){return allpasses[elem]->getDelayTime();}

float Moorer::getAllpassGain(const int elem){return allpasses[elem]->getGain();}

void Moorer::setCombGain(const float percent){
    
    for(int i = 0; i < 4; i++){
        
            float gain = 0.0f;
            gain = combs[i]->getGain*percent;
            combs[i]->setGain(gain);
        }
}

void Moorer::setAllpassGain(const int elem, const float g){allpasses[elem]->setGain(g);}


void Moorer::setAllpassDelay(const int elem, const int Fs, const float d){allpasses[elem]->setDelayTimeMS(Fs, d);}



float Moorer::processSample(const float in, const int channel){
    float combOut = 0.0f;
    float apf1Out = 0.0f;
    float apf2Out = 0.0f;
    float ers = 0.0f;
    float tapOut = 0.0f;
    
    //early reflect
    ers = er[0]->next(in,channel);
           
    tapOut = ers;
    
    //combs take output from early reflect generator
    for(int i = 0; i < 6; i++){
        combOut += combs[i]->processSample(tapOut * 0.25f,channel);
    }
    
    //output of combs fed to all pass
    apf1Out = allpasses[0]->processSample(combOut,channel);
    apf2Out = allpasses[1]->processSample(apf1Out,channel);
    
    return apf2Out;
    
}


