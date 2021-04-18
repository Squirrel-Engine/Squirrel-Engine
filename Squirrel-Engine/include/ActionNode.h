#pragma once
#include "AINode.h"
#include "Blackboard.h"
#include "EActionStatus.h"

class ActionNode : public AINode
{
public:
	virtual void onInitialize() = 0;
	virtual void onAction() = 0;
	virtual void onTerminate() = 0;

	EActionStatus actionStatus;
	Blackboard* blackBoard;

	bool isFreshStart = true;
	
};