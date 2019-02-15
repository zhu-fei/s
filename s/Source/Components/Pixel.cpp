/*
  ==============================================================================

    Pixel.cpp
    Created: 15 Feb 2019 7:52:53pm
    Author:  user

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Common/ComponentList.h"
#include "Pixel.h"

//==============================================================================
TPixel::TPixel(ValueTree& treeToShow) : _tree(treeToShow)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

TPixel::~TPixel()
{
}

void TPixel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
	return;
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Pixel", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void TPixel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

static ComponentList<TPixel> td((const String)("TPixel"), 2);