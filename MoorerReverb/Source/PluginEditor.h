/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SmallKnob.h"
#include "LargeKnob.h"

//==============================================================================
/**
*/
class MoorerReverbAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                          public juce::Slider::Listener
{
public:
    MoorerReverbAudioProcessorEditor (MoorerReverbAudioProcessor&);
    ~MoorerReverbAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;

private:
    ImageComponent backgroundImageComponent;
    
    Slider diffusionKnob;
    Label diffusionLabel;

    Slider reverbTimeKnob;
    Label reverbTimeLabel;
    
    Slider modulationKnob;
    Label modulationTimeKnob;

    Slider mixKnob;
    Label mixLabel;
    
    SmallKnob smallKnob;
    LargeKnob largeKnob;
    
    MoorerReverbAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoorerReverbAudioProcessorEditor)
};
