#pragma once
#include "ControllerBase.h"
#include "TextBase.h"

class StatusViewManager
{
public:
	static StatusViewManager& getInstance()
	{
		static StatusViewManager instance;
		return instance;
	}

	void addStatusView(ControllerBase* c);

	bool doStep(int);

private:
	StatusViewManager() {};               
	StatusViewManager(StatusViewManager const&);              
	void operator=(StatusViewManager const&);

	map<ControllerBase*, TextBase*> controllerToStatusView;

};

