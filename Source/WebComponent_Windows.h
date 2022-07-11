/*
  ==============================================================================

    WebComponent_Windows.h
    Created: 26 Jun 2022 11:13:15pm
    Author:  Abhishek Shivakumar

  ==============================================================================
*/

#pragma once

class DemoBrowserComponent  : public juce::WindowsWebView2BrowserComponent
{
public:
    //==============================================================================
    DemoBrowserComponent (juce::TextEditor& addressBox)
    : addressTextBox (addressBox), juce::WindowsWebView2BrowserComponent (true, File::getSpecialLocation  (File::SpecialLocationType::currentExecutableFile).getChildFile ("WebView2Loader.dll"))
    {
    }

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
