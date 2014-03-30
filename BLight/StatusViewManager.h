#pragma once
#include "ControllerBase.h"
#include "TextBase.h"
#include "IManager.h"

class StatusViewManager : public IManager
{
public:
	static StatusViewManager& getInstance()
	{
		static StatusViewManager instance;
		return instance;
	}

	void addStatusView(ControllerBase* c);
	void removeStatusView(ControllerBase* c);

	bool doStep(int);

private:
	StatusViewManager() {};               
	StatusViewManager(StatusViewManager const&);              
	void operator=(StatusViewManager const&);

	map<ControllerBase*, TextBase*> controllerToStatusView;

};

