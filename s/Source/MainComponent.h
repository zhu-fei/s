/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "./Common/ComponentList.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
						, public ListBoxModel
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;




	/////////////////////////////
	/////////////////////////////
	//////  ListBoxModel virual function implementation

	int getNumRows() override
	{

		return  TComponentType::getCompTypeList().size();
	}

	void paintListBoxItem(int rowNumber, Graphics& g, int width, int height, bool rowIsSelected) override
	{

		if (rowIsSelected)
			g.fillAll(Colours::deepskyblue);

		HashMap <int, TComponentType*>& hm = TComponentType::getCompTypeList();
		if (hm.contains(rowNumber))
		{
			TComponentType * ct = hm[rowNumber];
			AttributedString a;
			a.setJustification(Justification::centredLeft);
			a.append(ct->name, Font(20.0f), Colours::white);
			a.draw(g, Rectangle<int>(width + 10, height).reduced(6, 0).toFloat());
		}
	}



	void selectedRowsChanged(int lastRowSelected) override
	{
		if (_curComponentIndex == lastRowSelected)
		{
			return;
		}
		_curComponentIndex = lastRowSelected;
		HashMap <int, TComponentType*>& hm = TComponentType::getCompTypeList();
		if (hm.contains(lastRowSelected))
		{
			TComponentType * ct = hm[lastRowSelected];
			_curComponent = nullptr;
			_curComponent = ct->createComponent(_tree);
			addAndMakeVisible(_curComponent);
			//	_curSubComp->setFocusContainer(true);
			_curComponent->grabKeyboardFocus();
			resized();
		}
	}
	/////////////////////////////
	/////////////////////////////

public:
	ScopedPointer<ListBox> _lstBox;

	ScopedPointer<Component> _curComponent;

	int _curComponentIndex{ 0 };


	ValueTree _tree;
private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
