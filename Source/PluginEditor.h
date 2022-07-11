/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#ifdef _WIN32
    #include "WebComponent_Windows.h"
#elif __APPLE__
    #include "WebComponent_OSX.h"
#endif

//==============================================================================
/**
*/



class WebviewexampleAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WebviewexampleAudioProcessorEditor (WebviewexampleAudioProcessor&);
    ~WebviewexampleAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void paintOverChildren (juce::Graphics&) override;
    
    void resized() override;

private:

    juce::Image myimage = juce::ImageFileFormat::loadFrom (BinaryData::background_png, BinaryData::background_pngSize);
    
    std::unique_ptr<DemoBrowserComponent> webView;
    juce::ImageComponent BackgroundImageComponent;

    juce::TextEditor addressTextBox;

    juce::TextButton goButton      { "Go", "Go to URL" },
                     backButton    { "<<", "Back" },
                     forwardButton { ">>", "Forward" };

    void lookAndFeelChanged() override
    {
        addressTextBox.applyFontToAllText (addressTextBox.getFont());
    }
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WebviewexampleAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WebviewexampleAudioProcessorEditor)
};
