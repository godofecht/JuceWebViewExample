/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WebviewexampleAudioProcessorEditor::WebviewexampleAudioProcessorEditor (WebviewexampleAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque (true);
    
    // Create an address box..
    addAndMakeVisible (addressTextBox);
    addressTextBox.setTextToShowWhenEmpty ("Enter a web address, e.g. https://www.juce.com", juce::Colours::grey);
    addressTextBox.onReturnKey = [this] { webView->goToURL (addressTextBox.getText()); };

    // create the actual browser component
    webView.reset (new DemoBrowserComponent (addressTextBox));


    // add some buttons..
    addAndMakeVisible (goButton);
    goButton.onClick = [this] { webView->goToURL (addressTextBox.getText()); };
    addAndMakeVisible (backButton);
    backButton.onClick = [this] { webView->goBack(); };
    addAndMakeVisible (forwardButton);
    forwardButton.onClick = [this] { webView->goForward(); };

    // send the browser to a start page..
    webView->goToURL ("https://www.Collab.collabcollab.io");
    
    BackgroundImageComponent.setImage (myimage);
    
    BackgroundImageComponent.setImagePlacement (juce::RectanglePlacement::stretchToFit);
 //   BackgroundImageComponent.setAlwaysOnTop (true);

    
    addAndMakeVisible (webView.get());
    addAndMakeVisible (BackgroundImageComponent);


    setSize (1000, 650);
}

WebviewexampleAudioProcessorEditor::~WebviewexampleAudioProcessorEditor()
{
}   

//==============================================================================
void WebviewexampleAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
 //   g.drawImage (si, 0, 0, getWidth(), getHeight(), 0, 0, getWidth(), getWidth());

}

void WebviewexampleAudioProcessorEditor::paintOverChildren (juce::Graphics& g)
{
 //   g.drawImageTransformed (myimage, juce::AffineTransform::scale (1.0 / 5.0f));
}

void WebviewexampleAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    int xPos = 100;
    int yPos = 20; //49;
    
    webView->setBounds       (xPos, yPos, getWidth() - xPos * 2 - 1, getHeight() - yPos * 2);
    
    BackgroundImageComponent.setBounds (getLocalBounds());


    
//    BackgroundImageComponent.setBounds (getLocalBounds());
//    goButton      .setBounds (getWidth() - 45, 10, 35, 25);
//    addressTextBox.setBounds (100, 10, getWidth() - 155, 25);
//    backButton    .setBounds (10, 10, 35, 25);
//    forwardButton .setBounds (55, 10, 35, 25);
}
