/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
	:_tree("root")
{

	_lstBox = new ListBox("_lstBox");
	_lstBox->setModel(this);
	addAndMakeVisible(_lstBox);

	HashMap <int, TComponentType*>& hm = TComponentType::getCompTypeList();
	if (hm.contains(_curComponentIndex))
	{
		TComponentType * ct = hm[_curComponentIndex];
		_curComponent = nullptr;
		_curComponent = ct->createComponent(_tree);
		//_curSubComp->setFocusContainer(true);
		addAndMakeVisible(_curComponent);
	}



    //setSize (600, 400);
	Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
	float ratio = 0.618f;
	centreWithSize(int(r.getWidth() * ratio), int(r.getHeight()*ratio));
}

MainComponent::~MainComponent()
{
	_lstBox = nullptr;
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
	g.fillAll(Colours::black);

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
	
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

	auto r = getLocalBounds();
	int listBoxWidth = roundToInt(proportionOfWidth(0.2000f));
	if (_lstBox)
		_lstBox->setBounds(r.removeFromLeft(listBoxWidth));


	if (_curComponent)
		_curComponent->setBounds(r);



	

}
