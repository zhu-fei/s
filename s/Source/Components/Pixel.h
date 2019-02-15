/*
  ==============================================================================

    Pixel.h
    Created: 15 Feb 2019 7:52:53pm
    Author:  user

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class TPixel : public Component
			   , private OpenGLRenderer
{
public:
	TPixel(ValueTree& treeToShow);
    ~TPixel();

    void paint (Graphics&) override;
    void resized() override;
	void renderOpenGL() override
	{

	}

	void newOpenGLContextCreated() override
	{
		freeAllContextObjects();
	}

	void openGLContextClosing() override
	{
		freeAllContextObjects();
	}

	void freeAllContextObjects()
	{
		//_shader = nullptr;
		//_texture.release();
		//_texture2.release();
		//_texture3.release();
		//_texture4.release();
	}


private:
	ValueTree _tree;


	String _strVertex;
	String _strFrag;



private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TPixel)
};


