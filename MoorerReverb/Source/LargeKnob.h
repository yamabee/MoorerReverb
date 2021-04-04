/*
  ==============================================================================

    LargeKnob.h
    Created: 30 Mar 2021 7:08:02pm
    Author:  Erin Lindsey Yamabe

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class LargeKnob : public LookAndFeel_V4 {
    
public:
    LargeKnob() {};
    virtual ~LargeKnob() {};
    
    virtual void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) {
        
        Image knob;

        knob = ImageCache::getFromMemory(BinaryData::VSTKnobPurple121_png, BinaryData::VSTKnobPurple121_pngSize);
        const int nFrames = 121; /*knob.getHeight()/knob.getWidth();*/

        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        
        const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
        
        const float diameter = jmin(width, height);
        const float radius = diameter/2;
        const float centreX = x + width * 0.5f; // centre position of the space along x axis
        const float centreY = y + height * 0.5f; // centre position of space along y axis
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(knob, (int)rx, (int)ry, diameter, diameter, 0, frameIdx*knob.getWidth(), knob.getWidth(), knob.getWidth());

    }
    
private:
 
};
