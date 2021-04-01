//
//  KnobSmallBlack.h
//
//  Copyright © 2020 Eric Tarr. All rights reserved.
//  Code may not be distributed without permission
//
//  This class was created to override and customize the LookAndFeel of the default JUCE components
//

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __KnobSmallBlack__
#define __KnobSmallBlack__

//==============================================================================
// There are two options, Big White Knob with (below) and without the blue outline.
// Just inherit the desired LookAndFeel
class KnobSmallBlack : public LookAndFeel_V4 // inherit from LookAndFeel_V4
{
public:
    
    KnobSmallBlack(){};
    virtual ~KnobSmallBlack(){};
    
    virtual void drawRotarySlider    (    Graphics &     g,
                                      int     x,
                                      int     y,
                                      int     width,
                                      int     height,
                                      float     sliderPosProportional,
                                      float     rotaryStartAngle,
                                      float     rotaryEndAngle,
                                      Slider &     slider )
    {
        Image knob;
        
        knob = ImageCache::getFromMemory (BinaryData::knob_small_black_128_frames_png, BinaryData::knob_small_black_128_frames_pngSize);
        
        // Width and height of object comes from above "drawRotarySlider"
        const int nFrames = 128; //knob.getHeight()/knob.getWidth(); // number of frames for vertical film strip
        
        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); //value between 0 and 1 for current amount of rotation
        
        
        const int frameIdx = (int)ceil(fractRotation * ((double)nFrames-1.0) ); // Original current index from 0 --> nFrames-1
        
        const float radius = jmin (width / 2.0f, height / 2.0f) ;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius /*- 1.0f*/;
        const float ry = centreY - radius /* - 1.0f*/;
        
        // Vertical Sprite Sheet
        g.drawImage( knob, // image
                    (int)rx, (int)ry, width, height,   // dest
                    0, frameIdx*knob.getWidth(), knob.getWidth(), knob.getWidth()); // source
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KnobSmallBlack);
};

#endif   // KnobSmallBlack
