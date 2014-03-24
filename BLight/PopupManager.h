#pragma once
#include "PopupText.h"
#include "IManager.h"

class PopupManager : public IManager
{
public:
	static PopupManager& getInstance()
	{
		static PopupManager instance;
		return instance;
	}

	void add(PopupText*);

	bool doStep(int);

private:
	PopupManager() {};               
	PopupManager(PopupManager const&);              
	void operator=(PopupManager const&);

	vector<PopupText*> popUps;
};

