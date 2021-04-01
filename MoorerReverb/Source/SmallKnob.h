/*
  ==============================================================================

    SmallKnob.h
    Created: 30 Mar 2021 7:08:16pm
    Author:  Erin Lindsey Yamabe

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SmallKnob : public LookAndFeel_V4 {
    
public:
    SmallKnob() {};
    virtual ~SmallKnob() {};
    
    virtual void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) {
        
        Image knob;

        knob = ImageCache::getFromMemory(BinaryData::smallPurpleKnob_png, BinaryData::smallPurpleKnob_pngSize);
        const int nFrames = knob.getHeight()/knob.getWidth();

        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
        
        const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0));
        
        const float diameter = jmin(width, height);
        const float radius = diameter/2;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(knob, (int)rx, (int)ry, diameter, diameter, 0, frameIdx*knob.getWidth(), knob.getWidth(), knob.getWidth());

    }
    
private:
 
};
