/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MoorerReverb.h"


//==============================================================================
/**
*/
class MoorerReverbAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    MoorerReverbAudioProcessor();
    ~MoorerReverbAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
<<<<<<< HEAD
    int getSampleRate(int sampleRate); 
    
    int Fs;
    float timeMS; //time %
    float mixPercent = 50.f; //mix %
    float diffusion  = 50.f; //
    float modulation = 5.f    //0-20
 
=======
    float timePercent = 50.f; // sets gain of LPCF
    float mixPercent = 50.f; //
    float diffusionPercent = 50.f; // sets gain of APF
    float modulation = 0; // sets depth -> 0-20
>>>>>>> develop

private:
    MoorerReverb Moorer;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoorerReverbAudioProcessor)
};
