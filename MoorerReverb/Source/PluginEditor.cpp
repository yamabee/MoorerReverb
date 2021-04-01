/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MoorerReverbAudioProcessorEditor::MoorerReverbAudioProcessorEditor (MoorerReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    auto backgroundImage = ImageCache::getFromMemory(BinaryData::MoorerBackground_png, BinaryData::MoorerBackground_pngSize);
    
    if (!backgroundImage.isNull()) {
        backgroundImageComponent.setImage(backgroundImage, RectanglePlacement::stretchToFit);
    }
    else {
        jassert(! backgroundImage.isNull());
    }
    
    addAndMakeVisible(backgroundImageComponent);
    
    mixKnob.addListener(this);
    mixKnob.setRange(0, 1, 0.01);
    mixKnob.setValue(50);
    mixKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixKnob.setTextBoxStyle(Slider::NoTextBox, false, 75, 20);
    addAndMakeVisible(mixKnob);
    
    mixKnob.setLookAndFeel(&largeKnob);
    
    reverbTimeKnob.addListener(this);
    reverbTimeKnob.setRange(0.01, 1, 0.01);
    reverbTimeKnob.setValue(0.5);
    reverbTimeKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    reverbTimeKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);
    addAndMakeVisible(reverbTimeKnob);
    
    reverbTimeKnob.setLookAndFeel(&smallKnob);
    
    diffusionKnob.addListener(this);
    diffusionKnob.setRange(0.01, 1, 0.01);
    diffusionKnob.setValue(0.5);
    diffusionKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    diffusionKnob.setTextBoxStyle(Slider::TextBoxBelow, false,60, 20);
    addAndMakeVisible(diffusionKnob);
    
    diffusionKnob.setLookAndFeel(&smallKnob);
    
    modulationKnob.addListener(this);
    modulationKnob.setRange(0, 20, 1);
    modulationKnob.setValue(5);
    modulationKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    modulationKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);
    addAndMakeVisible(modulationKnob);
    
    modulationKnob.setLookAndFeel(&smallKnob);
    
    setSize (400, 300);
    setResizable(false, false);
}

MoorerReverbAudioProcessorEditor::~MoorerReverbAudioProcessorEditor()
{
}

//==============================================================================
void MoorerReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
}

void MoorerReverbAudioProcessorEditor::resized()
{
    backgroundImageComponent.setBounds(0.f, 0.f, 400.f, 300.f);
    
//    Rectangle<int> totalArea = getLocalBounds();
    Rectangle<int> mixSection(0, 80, 400, 120);
    Rectangle<int> mixKnobArea = mixSection.withTrimmedRight(150).withTrimmedLeft(150).withTrimmedBottom(20);
    
    Rectangle<int> smallKnobSection(0,180,400,120);
    Rectangle<int> timeKnobSection(40,160,140,140);
    Rectangle<int> timeKnobArea = timeKnobSection.withTrimmedRight(20).withTrimmedBottom(58).withTrimmedTop(18);
    
    Rectangle<int> diffusionKnobSection(220,160,140,140);
    Rectangle<int> diffusionKnobArea = diffusionKnobSection.withTrimmedLeft(20).withTrimmedBottom(58).withTrimmedTop(18);
    
    Rectangle<int> modulationKnobArea = smallKnobSection.withTrimmedLeft(150).withTrimmedRight(150).withTrimmedTop(28).withTrimmedBottom(28);
    
    reverbTimeKnob.setBounds(timeKnobArea);
    mixKnob.setBounds(mixKnobArea);
    diffusionKnob.setBounds(diffusionKnobArea);
    modulationKnob.setBounds(modulationKnobArea);
    
}

void MoorerReverbAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    if (slider == &reverbTimeKnob) {
        audioProcessor.timePercent = reverbTimeKnob.getValue();
    }
}
