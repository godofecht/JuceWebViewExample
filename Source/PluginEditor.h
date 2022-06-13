/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/

class DemoBrowserComponent  : public juce::WebBrowserComponent
{
public:
    //==============================================================================
    DemoBrowserComponent (juce::TextEditor& addressBox)
        : addressTextBox (addressBox)
    {}

    // This method gets called when the browser is about to go to a new URL..
    bool pageAboutToLoad (const juce::String& newURL) override
    {
        // We'll just update our address box to reflect the new location..
        addressTextBox.setText (newURL, false);

        // we could return false here to tell the browser not to go ahead with
        // loading the page.
        return true;
    }

    // This method gets called when the browser is requested to launch a new window
    void newWindowAttemptingToLoad (const juce::String& newURL) override
    {
        // We'll just load the URL into the main window
        goToURL (newURL);
    }

private:
    juce::TextEditor& addressTextBox;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DemoBrowserComponent)
};


class WebviewexampleAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WebviewexampleAudioProcessorEditor (WebviewexampleAudioProcessor&);
    ~WebviewexampleAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ScaledImage si;    
    juce::Image myimage = juce::ImageFileFormat::loadFrom (BinaryData::background_png, BinaryData::background_pngSize);
    
    std::unique_ptr<DemoBrowserComponent> webView;

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
