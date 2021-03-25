/*
  ==============================================================================

    APF.h
    Created: 25 Mar 2021 2:12:49pm
    Author:  Mitchell Elliott

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#pragma once

// Class for implimenting colorless reverb using an
// All pass filter
class APF{
public:
    APF();
    void processAPF();
    void setAPFParams();
    
private:
    
    
};
