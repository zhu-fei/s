/*
  ==============================================================================

    commponentList.h
    Created: 15 Feb 2019 4:53:44pm
    Author:  user

  ==============================================================================
*/

#pragma once




class TComponentType
{
public:
	virtual Component* createComponent() = 0;
	TComponentType(const String &n, int index) : name(n), _index(index)
	{
		getCompTypeList().set(index, (TComponentType*)this);
		//getCompTypeList().set(n, (TComponentType*)this);

	}


	static HashMap <int, TComponentType*>& getCompTypeList()
	{
		static HashMap <int, TComponentType*> list;

		return list;
	}
	String name;
	int _index;
};



template <class TComponent>
class ComponentList : TComponentType
{
public:
	ComponentList(const  String & n, int index) : TComponentType(n, index)
	{
	}

	virtual Component* createComponent()
	{
		return new TComponent();
	}
};